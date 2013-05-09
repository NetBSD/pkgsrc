$NetBSD: patch-modules_pipebackend_pipebackend.cc,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- modules/pipebackend/pipebackend.cc.orig	2013-05-09 15:20:34.000000000 +0000
+++ modules/pipebackend/pipebackend.cc
@@ -91,7 +91,7 @@ PipeBackend::PipeBackend(const string &s
    signal(SIGCHLD, SIG_IGN);
    setArgPrefix("pipe"+suffix);
    try {
-     d_coproc=shared_ptr<CoWrapper>(new CoWrapper(getArg("command"), getArgAsNum("timeout")));
+     d_coproc=boost::shared_ptr<CoWrapper>(new CoWrapper(getArg("command"), getArgAsNum("timeout")));
      d_regex=getArg("regex").empty() ? 0 : new Regex(getArg("regex"));
      d_regexstr=getArg("regex");
    }
