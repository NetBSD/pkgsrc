$NetBSD: patch-pdf2djvu.cc,v 1.2 2015/04/24 20:18:48 joerg Exp $

--- pdf2djvu.cc.orig	2012-09-18 15:27:41.000000000 +0000
+++ pdf2djvu.cc
@@ -210,6 +210,13 @@ public:
   friend Command &operator <<(Command &, const Component &);
 };
 
+Command &operator <<(Command &command, const File &arg)
+{
+  const std::string filename(arg);
+  command << filename;
+  return command;
+}
+
 Command &operator <<(Command &command, const Component &component)
 {
   command << *component.file;
@@ -625,8 +632,8 @@ public:
     this->fill(state);
   }
 
-  MutedRenderer(pdf::splash::Color &paper_color, bool monochrome, const ComponentList &page_files)
-  : Renderer(paper_color, monochrome), page_files(page_files)
+  MutedRenderer(pdf::splash::Color &paper_color, bool monochrome, bool antialias, const ComponentList &page_files)
+  : Renderer(paper_color, monochrome, antialias), page_files(page_files)
   {
     this->clear();
   }
@@ -1252,7 +1259,6 @@ static int xmain(int argc, char * const 
     throw StdoutIsATerminal();
 
   pdf::Environment environment(argv[0]);
-  environment.set_antialias(config.antialias);
 
   DocumentMap document_map(config.filenames);
   intmax_t pdf_byte_size = document_map.get_byte_size();
@@ -1386,13 +1392,13 @@ static int xmain(int argc, char * const 
         debug(1) << doc->getFileName()->getCString() << ":" << std::endl;
         debug(0)++;
       }
-      out1.reset(new pdf::Renderer(paper_color, config.monochrome));
+      out1.reset(new pdf::Renderer(paper_color, config.monochrome, config.antialias));
       out1->start_doc(doc.get());
-      outm.reset(new MutedRenderer(paper_color, config.monochrome, *page_files));
+      outm.reset(new MutedRenderer(paper_color, config.monochrome, config.antialias, *page_files));
       outm->start_doc(doc.get());
       if (!config.monochrome)
       {
-        outs.reset(new MutedRenderer(paper_color, config.monochrome, *page_files));
+        outs.reset(new MutedRenderer(paper_color, config.monochrome, config.antialias, *page_files));
         outs->start_doc(doc.get());
       }
     }
