$NetBSD: patch-go.mod,v 1.1 2022/04/20 10:10:59 khorben Exp $

--- go.mod.orig	2022-03-29 06:02:20.000000000 +0000
+++ go.mod
@@ -2,8 +2,11 @@ module go.nanomsg.org/mangos/v3
 
 require (
 	github.com/Microsoft/go-winio v0.5.2
+	github.com/davecgh/go-spew v1.1.1 // indirect
 	github.com/gdamore/optopia v0.2.0
 	github.com/gorilla/websocket v1.5.0
+	github.com/sirupsen/logrus v1.7.0 // indirect
+	github.com/stretchr/objx v0.3.0 // indirect
 )
 
 go 1.13
