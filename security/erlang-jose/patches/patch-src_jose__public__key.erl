$NetBSD: patch-src_jose__public__key.erl,v 1.1 2018/07/20 09:55:47 fhajny Exp $

Workaround to build on Erlang 21.
https://github.com/potatosalad/erlang-jose/pull/55

--- src/jose_public_key.erl.orig	2017-05-19 01:49:53.000000000 +0000
+++ src/jose_public_key.erl
@@ -12,6 +12,10 @@
 
 -include("jose_public_key.hrl").
 
+-ifdef(OTP_RELEASE).
+-compile({nowarn_deprecated_function, [{erlang, get_stacktrace, 0}]}).
+-endif.
+
 %% API
 -export([der_decode/2]).
 -export([der_encode/2]).
