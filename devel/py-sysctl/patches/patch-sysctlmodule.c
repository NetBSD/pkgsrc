$NetBSD: patch-sysctlmodule.c,v 1.2 2019/09/15 15:17:06 fox Exp $

Port to python 3

Fixes how new integer data is inserted into nodes. It now sets the
CTL_IMMEDIATE flag and value is placed in sysctl_idata. This fixes
the failing test for creating and destroying integer type nodes.

--- sysctlmodule.c.orig	2010-04-10 17:41:18.000000000 +0000
+++ sysctlmodule.c
@@ -33,7 +33,22 @@
 #include <errno.h>
 #include <sys/sysctl.h>
 
-/* 
+struct module_state {
+    PyObject *error;
+};
+
+#if PY_MAJOR_VERSION >= 3
+#define PyInt_AsLong			PyLong_AsLong
+#define PyInt_CheckExact		PyLong_CheckExact
+#define PyString_CheckExact(val)	PyUnicode_CheckExact(val)
+#define PyString_FromStringAndSize	PyUnicode_FromStringAndSize
+#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
+#else
+#define GETSTATE(m) (&_state)
+static struct module_state _state;
+#endif
+
+/*
  * create Python object of type similar to the MIB node 'name'
  * This is basically the laziest way to do this, as we outsource the
  * type recognition to the sysctl(3) API. Fantastic! :-)
@@ -94,9 +109,9 @@ node_to_object(const char *name, void *v
 	return o;
 }
 
-/* 
+/*
  * SYSCTL_TYPEMASK is used as an error type. This is an implementation
- * detail. 
+ * detail.
  */
 static uint32_t
 nodetype(char *nodepath)
@@ -104,14 +119,12 @@ nodetype(char *nodepath)
 
 	int rv;
 	char cname[SYSCTL_NAMELEN];
-	int csz;
+	size_t csz = SYSCTL_NAMELEN;
 
 	struct sysctlnode *rnode = NULL;
 
 	assert (nodepath != NULL);
 
-	csz = SYSCTL_NAMELEN;
-
 	rv = sysctlgetmibinfo(nodepath, NULL, NULL, cname, &csz, &rnode, SYSCTL_VERSION);
 
 	if (rv == -1 || rnode == NULL) {
@@ -133,7 +146,7 @@ nodetype(char *nodepath)
  * discarded ),  and a new one, with requested string is assigned.
  *
  * XXX: This is a workaround for sysctl(3) not allowing strings longer
- * than the current value. 
+ * than the current value.
  * See: http://mail-index.netbsd.org/tech-kern/2009/10/22/msg006329.html
  */
 
@@ -149,7 +162,7 @@ write_sysctl_string(char *name, char *va
 	size_t nodelen;
 
 	char cname[SYSCTL_NAMELEN];
-	int csz = SYSCTL_NAMELEN;
+	size_t csz = SYSCTL_NAMELEN;
 
 	/* Sanity checks */
 
@@ -237,7 +250,7 @@ read_sysctl(PyObject *self, PyObject *ar
 {
 	PyObject *o;
 	void *val;
-	size_t len;
+	size_t len = 0;
 	const char *name;
 	int rv;
 
@@ -245,9 +258,7 @@ read_sysctl(PyObject *self, PyObject *ar
 		return NULL;
 
 getbyname:
-	val = NULL;
-	len = 0;
-
+	len += 4;
 	rv = sysctlbyname(name, NULL, &len, NULL, 0);
 
 	if (rv == -1) {
@@ -256,7 +267,7 @@ getbyname:
 	}
 
 	val = malloc(len);
-	if (val ==NULL) {
+	if (val == NULL) {
 		PyErr_NoMemory();
 		return NULL;
 	}
@@ -309,7 +320,7 @@ write_sysctl(PyObject *self, PyObject *a
 
 	/* Arrange to obtain the oldvalue */
 	oldval = NULL;
-	len = 0;
+	len = 4;
 
 	rv = sysctlbyname(name, NULL, &len, NULL, 0);
 
@@ -350,7 +361,7 @@ write_sysctl(PyObject *self, PyObject *a
 			return NULL;
 		}
 
-		/* 
+		/*
 		 * Strings are handled specially. We just use
 		 * read_sysctl() to record the previous string value.
 		 * We ignore and free(oldval)
@@ -424,7 +435,7 @@ getnewleafname(const char *name, char *c
 
 /*
  * Get the common prefix of name from what's already in the MIB and
- * what's been requested 
+ * what's been requested
  */
 static void
 getprefixname(const char *name, char *pname)
@@ -445,7 +456,7 @@ create_node(const char *name, int ctl_ty
 {
 
 	int mib[CTL_MAXNAME];
-	u_int miblen = CTL_MAXNAME;
+	size_t miblen = CTL_MAXNAME;
 
 	char cname[SYSCTL_NAMELEN]; /* Canonical name */
 	char pname[SYSCTL_NAMELEN]; /* The Canonical prefix */
@@ -456,6 +467,7 @@ create_node(const char *name, int ctl_ty
 	struct sysctlnode node;
 	size_t nodelen;
 
+
 	/* Check for NULL ptr dereference */
 	assert (value != NULL || vlen == 0);
 
@@ -504,7 +516,12 @@ create_node(const char *name, int ctl_ty
 	memset(&node, 0, nodelen);
 	node.sysctl_num = CTL_CREATE;
 	node.sysctl_flags = SYSCTL_VERSION | flags | ctl_type;
-	node.sysctl_data = value;
+	if (ctl_type == CTLTYPE_INT) {
+	  node.sysctl_idata = *(int *) value;
+	}
+	else {
+	  node.sysctl_data = value;
+	}
 	node.sysctl_size = vlen;
 
 	snprintf(node.sysctl_name, csz + 1, cname);
@@ -533,7 +550,7 @@ create_sysctl(PyObject *self, PyObject *
 	const char *typename = NULL;
 	size_t typelen = 0;
 
-	int len, rv;
+	int rv;
 
 	/* XXX: Royal mess... needs more thought */
 	if (!PyArg_ParseTuple(args, "s|s#O: Incorrect values passed to sysctl.write", &name, &typename, &typelen, &value)) {
@@ -546,7 +563,7 @@ create_sysctl(PyObject *self, PyObject *
 	}
 
 	/* XXX: Arrange to obtain the oldvalue */
-	len = 0;
+	/*len = 4;*/
 
 	if ((typename == NULL && typelen == 0)
 	    || (!strncmp(typename, "CTLTYPE_NODE", typelen)) ) {
@@ -578,7 +595,7 @@ create_sysctl(PyObject *self, PyObject *
 			}
 		}
 
-		if (!create_node(name, CTLTYPE_INT, CTLFLAG_READWRITE, &intval, sizeof intval)) {
+		if (!create_node(name, CTLTYPE_INT, CTLFLAG_READWRITE|CTLFLAG_IMMEDIATE, &intval, sizeof intval)) {
 			return NULL;
 		} else {
 			Py_RETURN_NONE;
@@ -593,7 +610,12 @@ create_sysctl(PyObject *self, PyObject *
 				PyErr_SetString(PyExc_TypeError, "Value passed is of wrong type");
 				return NULL;
 			}
+#if PY_MAJOR_VERSION >= 3
+			strval = (char *) PyUnicode_AsUTF8AndSize(value, &vlen);
+			if (strval == NULL) {
+#else
 			if (-1 == PyString_AsStringAndSize(value, &strval, &vlen)) {
+#endif
 				PyErr_SetString(PyExc_TypeError, "Error decoding string from buffer \n");
 				return NULL;
 			}
@@ -682,9 +704,9 @@ destroy_sysctl(PyObject *self, PyObject 
 }
 
 static PyMethodDef sysctl_methods[] = {
-	{ "read", read_sysctl, METH_VARARGS, 
+	{ "read", read_sysctl, METH_VARARGS,
 	  "read value from sysctl node." },
-	{ "write", write_sysctl, METH_VARARGS, 
+	{ "write", write_sysctl, METH_VARARGS,
 	  "write value to sysctl node." },
 	{ "create", create_sysctl, METH_VARARGS,
 	  "create a sysctl node." },
@@ -694,8 +716,61 @@ static PyMethodDef sysctl_methods[] = {
 };
 
 
+
+#if PY_MAJOR_VERSION >= 3
+
+static int sysctl_traverse(PyObject *m, visitproc visit, void *arg) {
+    Py_VISIT(GETSTATE(m)->error);
+    return 0;
+}
+
+static int sysctl_clear(PyObject *m) {
+    Py_CLEAR(GETSTATE(m)->error);
+    return 0;
+}
+
+
+static struct PyModuleDef moduledef = {
+        PyModuleDef_HEAD_INIT,
+        "sysctl",
+        NULL,
+        sizeof(struct module_state),
+        sysctl_methods,
+        NULL,
+        sysctl_traverse,
+        sysctl_clear,
+        NULL
+};
+
+#define INITERROR return NULL
+
 PyMODINIT_FUNC
+PyInit_sysctl(void)
+
+#else
+#define INITERROR return
+
+void
 initsysctl(void)
+#endif
 {
-	(void) Py_InitModule("sysctl", sysctl_methods);
+#if PY_MAJOR_VERSION >= 3
+    PyObject *module = PyModule_Create(&moduledef);
+#else
+    PyObject *module = Py_InitModule("sysctl", sysctl_methods);
+#endif
+
+    if (module == NULL)
+        INITERROR;
+    struct module_state *st = GETSTATE(module);
+
+    st->error = PyErr_NewException("sysctl.Error", NULL, NULL);
+    if (st->error == NULL) {
+        Py_DECREF(module);
+        INITERROR;
+    }
+
+#if PY_MAJOR_VERSION >= 3
+    return module;
+#endif
 }
