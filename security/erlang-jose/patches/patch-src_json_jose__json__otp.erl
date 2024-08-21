$NetBSD: patch-src_json_jose__json__otp.erl,v 1.1 2024/08/21 15:00:33 adam Exp $

Support OTP json module
https://github.com/potatosalad/erlang-jose/pull/176

--- src/json/jose_json_otp.erl.orig	2024-08-21 12:50:10.251898530 +0000
+++ src/json/jose_json_otp.erl
@@ -0,0 +1,20 @@
+%% -*- mode: erlang; tab-width: 4; indent-tabs-mode: 1; st-rulers: [70] -*-
+%% vim: ts=4 sw=4 ft=erlang noet
+-module(jose_json_otp).
+-behaviour(jose_json).
+
+%% jose_json callbacks
+-export([decode/1]).
+-export([encode/1]).
+
+%%====================================================================
+%% jose_json callbacks
+%%====================================================================
+
+decode(Binary) -> json:decode(Binary).
+
+encode(Term) -> iolist_to_binary(json:encode(Term)).
+
+%%%-------------------------------------------------------------------
+%%% Internal functions
+%%%-------------------------------------------------------------------
