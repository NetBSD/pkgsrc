$NetBSD: patch-cmd_podman_machine_init.go,v 1.3 2023/02/14 00:33:13 tnn Exp $

Disable the virtfs volume driver by default.
Doesn't work yet on NetBSD.

--- cmd/podman/machine/init.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ cmd/podman/machine/init.go
@@ -101,7 +101,7 @@ func init() {
 	_ = initCmd.RegisterFlagCompletionFunc(VolumeFlagName, completion.AutocompleteDefault)
 
 	VolumeDriverFlagName := "volume-driver"
-	flags.StringVar(&initOpts.VolumeDriver, VolumeDriverFlagName, "", "Optional volume driver")
+	flags.StringVar(&initOpts.VolumeDriver, VolumeDriverFlagName, "none", "Optional volume driver")
 	_ = initCmd.RegisterFlagCompletionFunc(VolumeDriverFlagName, completion.AutocompleteDefault)
 
 	IgnitionPathFlagName := "ignition-path"
