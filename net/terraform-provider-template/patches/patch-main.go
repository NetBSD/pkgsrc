$NetBSD: patch-main.go,v 1.1 2021/03/10 23:24:00 tpaul Exp $

The template provider has been archived and is only available on the Hashicorp
Github account.

--- main.go.orig	2020-10-08 16:14:35.000000000 +0000
+++ main.go
@@ -2,7 +2,7 @@ package main
 
 import (
 	"github.com/hashicorp/terraform/plugin"
-	"github.com/terraform-providers/terraform-provider-template/template"
+	"github.com/hashicorp/terraform-provider-template/template"
 )
 
 func main() {
