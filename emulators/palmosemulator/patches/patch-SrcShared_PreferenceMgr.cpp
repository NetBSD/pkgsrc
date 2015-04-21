$NetBSD: patch-SrcShared_PreferenceMgr.cpp,v 1.1 2015/04/21 17:15:20 joerg Exp $

--- SrcShared/PreferenceMgr.cpp.orig	2002-03-29 13:11:17.000000000 +0000
+++ SrcShared/PreferenceMgr.cpp
@@ -232,58 +232,6 @@ void BasePreference::Save (void)
 //
 // ----------------------------------------------------------------------
 
-
-/***********************************************************************
- *
- * FUNCTION:	Preference<T> constructor
- *
- * DESCRIPTION: Calls BasePreference to initialize the base members,
- *				then calls Load() to load the data.
- *
- * PARAMETERS:	name - name of the key used to fetch the data.
- *
- * RETURNED:	Nothing.
- *
- ***********************************************************************/
-
-template <class T>
-Preference<T>::Preference (PrefKeyType name, bool acquireLock) :
-	BasePreference (name, acquireLock),
-	fValue (T())
-{
-	this->Load ();
-}
-
-template <class T>
-Preference<T>::Preference (long index, bool acquireLock) :
-	BasePreference (index, acquireLock),
-	fValue (T())
-{
-	this->Load ();
-}
-
-
-	
-/***********************************************************************
- *
- * FUNCTION:	Preference<T> destructor
- *
- * DESCRIPTION: Ensures that any changes are flushed back to the
- *				preference collection before destructing the base class.
- *
- * PARAMETERS:	None.
- *
- * RETURNED:	Nothing.
- *
- ***********************************************************************/
-
-template <class T>
-Preference<T>::~Preference (void)
-{
-	this->Save ();
-}
-
-
 /***********************************************************************
  *
  * FUNCTION:	Preference<T>::DoLoad
