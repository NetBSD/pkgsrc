$NetBSD: patch-modules_pipebackend_pipebackend.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- modules/pipebackend/pipebackend.cc.orig	2015-03-02 13:17:08.000000000 +0000
+++ modules/pipebackend/pipebackend.cc
@@ -92,7 +92,7 @@ PipeBackend::PipeBackend(const string &s
    signal(SIGCHLD, SIG_IGN);
    setArgPrefix("pipe"+suffix);
    try {
-     d_coproc=shared_ptr<CoWrapper>(new CoWrapper(getArg("command"), getArgAsNum("timeout")));
+     d_coproc=boost::shared_ptr<CoWrapper>(new CoWrapper(getArg("command"), getArgAsNum("timeout")));
      d_regex=getArg("regex").empty() ? 0 : new Regex(getArg("regex"));
      d_regexstr=getArg("regex");
      d_abiVersion = ::arg().asNum("pipebackend-abi-version");
