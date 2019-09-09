$NetBSD: patch-sysctlmodule.c,v 1.1 2019/09/09 07:09:47 maya Exp $

Port to python 3

--- sysctlmodule.c.orig	2010-04-10 17:41:18.000000000 +0000
+++ sysctlmodule.c
@@ -33,6 +33,21 @@
 #include <errno.h>
 #include <sys/sysctl.h>
 
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
 /* 
  * create Python object of type similar to the MIB node 'name'
  * This is basically the laziest way to do this, as we outsource the
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
 
@@ -533,7 +545,7 @@ create_sysctl(PyObject *self, PyObject *
 	const char *typename = NULL;
 	size_t typelen = 0;
 
-	int len, rv;
+	int rv;
 
 	/* XXX: Royal mess... needs more thought */
 	if (!PyArg_ParseTuple(args, "s|s#O: Incorrect values passed to sysctl.write", &name, &typename, &typelen, &value)) {
@@ -546,7 +558,7 @@ create_sysctl(PyObject *self, PyObject *
 	}
 
 	/* XXX: Arrange to obtain the oldvalue */
-	len = 0;
+	/*len = 4;*/
 
 	if ((typename == NULL && typelen == 0)
 	    || (!strncmp(typename, "CTLTYPE_NODE", typelen)) ) {
@@ -593,7 +605,12 @@ create_sysctl(PyObject *self, PyObject *
 				PyErr_SetString(PyExc_TypeError, "Value passed is of wrong type");
 				return NULL;
 			}
+#if PY_MAJOR_VERSION >= 3
+			strval = PyUnicode_AsUTF8AndSize(value, &vlen);
+			if (strval == NULL) {
+#else
 			if (-1 == PyString_AsStringAndSize(value, &strval, &vlen)) {
+#endif
 				PyErr_SetString(PyExc_TypeError, "Error decoding string from buffer \n");
 				return NULL;
 			}
@@ -694,8 +711,61 @@ static PyMethodDef sysctl_methods[] = {
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
