$NetBSD: patch-pdf-backend.hh,v 1.1 2015/04/24 20:18:48 joerg Exp $

--- pdf-backend.hh.orig	2015-04-24 18:53:21.000000000 +0000
+++ pdf-backend.hh
@@ -113,7 +113,7 @@ namespace pdf
   class Renderer : public pdf::splash::OutputDevice
   {
   public:
-    Renderer(pdf::splash::Color &paper_color, bool monochrome = false) :
+    Renderer(pdf::splash::Color &paper_color, bool antialias, bool monochrome) :
       pdf::splash::OutputDevice(monochrome ? splashModeMono1 : splashModeRGB8, 4, gFalse, paper_color)
     { }
 
@@ -296,7 +296,6 @@ namespace pdf
   {
   public:
     Environment(const char *argv0);
-    void set_antialias(bool value);
     class UnableToSetParameter : public std::runtime_error
     {
     public:
