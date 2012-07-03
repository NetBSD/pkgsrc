$NetBSD: patch-avidemux_ADM__coreUI_include_DIA__factory.h,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_coreUI/include/DIA_factory.h.orig	2012-07-03 11:24:33.000000000 +0000
+++ avidemux/ADM_coreUI/include/DIA_factory.h
@@ -206,7 +206,7 @@ public:
 };
 /*********************************************/
 typedef diaElem *CREATE_TOGGLE_UINT(uint32_t *toggleValue,const char *toggleTitle, uint32_t *uintval, 
-								const char *name,uint32_t min,uint32_t max,const char *tip=NULL);
+								const char *name,uint32_t min,uint32_t max,const char *tip);
 class diaElemToggleUint : public diaElem
 {
   protected:
@@ -226,7 +226,7 @@ public:
   int getRequiredLayout(void);
 };
 typedef diaElem *CREATE_TOGGLE_INT(uint32_t *toggleValue,const char *toggleTitle, int32_t *intval, 
-									const char *name,int32_t min,int32_t max,const char *tip=NULL);
+									const char *name,int32_t min,int32_t max,const char *tip);
 class diaElemToggleInt : public diaElem
 {
   protected:
@@ -620,7 +620,7 @@ public:
   void updateMe(void);
 };
 /**********************************************/
-typedef diaElem *(CREATE_THREADCOUNT_T)(uint32_t *value, const char *title, const char *tip = NULL);
+typedef diaElem *(CREATE_THREADCOUNT_T)(uint32_t *value, const char *title, const char *tip);
 class diaElemThreadCount : public diaElem
 {
 
@@ -634,7 +634,7 @@ public:
   void updateMe(void);
 };
 /**********************************************/
-typedef diaElem *(CREATE_ASPECTRATIO_T)(uint32_t *value, const char *title, const char *tip = NULL);
+typedef diaElem *(CREATE_ASPECTRATIO_T)(uint32_t *value, const char *title, const char *tip);
 class diaElemAspectRatio : public diaElem
 {
 public:
