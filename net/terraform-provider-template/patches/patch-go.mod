$NetBSD: patch-go.mod,v 1.1 2026/08/27 20:25:58 leot Exp $

The template provider has been archived and is only available on the Hashicorp
Github account.

--- go.mod.orig	2026-03-02 20:59:56.042219058 +0000
+++ go.mod
@@ -1,8 +1,61 @@
 module github.com/terraform-providers/terraform-provider-template
 
 require (
-	github.com/hashicorp/hcl v1.0.0 // indirect
 	github.com/hashicorp/hcl2 v0.0.0-20190416162332-2c5a4b7d729a
 	github.com/hashicorp/terraform v0.12.0-alpha4.0.20190424121927-9327eedb0417
+	github.com/hashicorp/terraform-provider-template v1.0.0
 	github.com/zclconf/go-cty v0.0.0-20190320224746-fd76348b9329
 )
+
+require (
+	github.com/agext/levenshtein v1.2.2 // indirect
+	github.com/apparentlymart/go-cidr v1.0.0 // indirect
+	github.com/apparentlymart/go-textseg v1.0.0 // indirect
+	github.com/armon/go-radix v1.0.0 // indirect
+	github.com/aws/aws-sdk-go v1.16.36 // indirect
+	github.com/bgentry/go-netrc v0.0.0-20140422174119-9fd32a8b3d3d // indirect
+	github.com/bgentry/speakeasy v0.1.0 // indirect
+	github.com/blang/semver v3.5.1+incompatible // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/fatih/color v1.7.0 // indirect
+	github.com/golang/protobuf v1.3.0 // indirect
+	github.com/google/go-cmp v0.2.0 // indirect
+	github.com/hashicorp/errwrap v1.0.0 // indirect
+	github.com/hashicorp/go-cleanhttp v0.5.0 // indirect
+	github.com/hashicorp/go-getter v1.1.0 // indirect
+	github.com/hashicorp/go-hclog v0.0.0-20181001195459-61d530d6c27f // indirect
+	github.com/hashicorp/go-multierror v1.0.0 // indirect
+	github.com/hashicorp/go-plugin v0.0.0-20190322172744-52e1c4730856 // indirect
+	github.com/hashicorp/go-safetemp v1.0.0 // indirect
+	github.com/hashicorp/go-uuid v1.0.1 // indirect
+	github.com/hashicorp/go-version v1.1.0 // indirect
+	github.com/hashicorp/hcl v1.0.0 // indirect
+	github.com/hashicorp/hil v0.0.0-20190212112733-ab17b08d6590 // indirect
+	github.com/hashicorp/logutils v1.0.0 // indirect
+	github.com/hashicorp/terraform-config-inspect v0.0.0-20190327195015-8022a2663a70 // indirect
+	github.com/hashicorp/yamux v0.0.0-20180604194846-3520598351bb // indirect
+	github.com/jmespath/go-jmespath v0.0.0-20180206201540-c2b33e8439af // indirect
+	github.com/mattn/go-colorable v0.1.1 // indirect
+	github.com/mattn/go-isatty v0.0.5 // indirect
+	github.com/mitchellh/cli v1.0.0 // indirect
+	github.com/mitchellh/colorstring v0.0.0-20190213212951-d06e56a500db // indirect
+	github.com/mitchellh/copystructure v1.0.0 // indirect
+	github.com/mitchellh/go-homedir v1.0.0 // indirect
+	github.com/mitchellh/go-testing-interface v1.0.0 // indirect
+	github.com/mitchellh/go-wordwrap v1.0.0 // indirect
+	github.com/mitchellh/hashstructure v1.0.0 // indirect
+	github.com/mitchellh/mapstructure v1.1.2 // indirect
+	github.com/mitchellh/reflectwalk v1.0.0 // indirect
+	github.com/oklog/run v1.0.0 // indirect
+	github.com/posener/complete v1.2.1 // indirect
+	github.com/spf13/afero v1.2.1 // indirect
+	github.com/ulikunitz/xz v0.5.5 // indirect
+	github.com/vmihailenco/msgpack v4.0.1+incompatible // indirect
+	golang.org/x/crypto v0.0.0-20190308221718-c2843e01d9a2 // indirect
+	golang.org/x/net v0.0.0-20190311183353-d8887717615a // indirect
+	golang.org/x/sys v0.0.0-20190222072716-a9d3bda3a223 // indirect
+	golang.org/x/text v0.3.1-0.20180807135948-17ff2d5776d2 // indirect
+	google.golang.org/appengine v1.4.0 // indirect
+	google.golang.org/genproto v0.0.0-20190201180003-4b09977fb922 // indirect
+	google.golang.org/grpc v1.18.0 // indirect
+)
