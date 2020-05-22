$NetBSD: patch-src_lever_deployment__tasks.cc,v 1.1 2020/05/22 13:45:29 joerg Exp $

boost no longer uses boost::placeholders by default.

--- src/lever/deployment_tasks.cc.orig	2020-05-22 12:32:26.730921261 +0000
+++ src/lever/deployment_tasks.cc
@@ -291,7 +291,7 @@ bool SchemaUpdate::Run(Deployer* deploye
   }
   LOG(INFO) << "preparing dictionary '" << dict_name << "'.";
   DictFileFinder finder =
-      boost::bind(&find_dict_file, _1, shared_data_path, user_data_path);
+      boost::bind(&find_dict_file, boost::placeholders::_1, shared_data_path, user_data_path);
   DictCompiler dict_compiler(dict.get(), finder);
   if (verbose_) {
     dict_compiler.set_options(DictCompiler::kRebuild | DictCompiler::kDump);
