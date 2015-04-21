$NetBSD: patch-SrcShared_PreferenceMgr.h,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/PreferenceMgr.h.orig	2015-04-17 19:45:54.000000000 +0000
+++ SrcShared/PreferenceMgr.h
@@ -115,9 +115,24 @@ template <class T>
 class Preference : public BasePreference
 {
 	public:
-								Preference			(PrefKeyType name, bool = true);
-								Preference			(long index, bool = true);
-		virtual 				~Preference 		(void);
+	    Preference (PrefKeyType name, bool acquireLock = true) :
+		BasePreference (name, acquireLock),
+		fValue (T())
+	    {
+	    	this->Load ();
+	    }
+
+	    Preference (long index, bool acquireLock = true) :
+	    	BasePreference (index, acquireLock),
+	    	fValue (T())
+	    {
+	    	this->Load ();
+	    }
+
+	    ~Preference ()
+	    {
+	    	this->Save ();
+	    }
 
 	// I would *like* to have these operators.	That way, I could pass in a
 	// "Preference<Foo>" any place that accepts a "const Foo&" as a parameter.
