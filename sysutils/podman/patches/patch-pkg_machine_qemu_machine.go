$NetBSD: patch-pkg_machine_qemu_machine.go,v 1.3 2023/02/14 00:33:13 tnn Exp $

Disable the virtfs volume driver by default.
Doesn't work yet on NetBSD.

--- pkg/machine/qemu/machine.go.orig	2023-02-08 19:03:18.000000000 +0000
+++ pkg/machine/qemu/machine.go
@@ -46,6 +46,7 @@ func GetVirtualizationProvider() machine
 
 const (
 	VolumeTypeVirtfs     = "virtfs"
+	VolumeTypeNone       = "none"
 	MountType9p          = "9p"
 	dockerSock           = "/var/run/docker.sock"
 	dockerConnectTimeout = 5 * time.Second
@@ -291,6 +292,8 @@ func (v *MachineVM) Init(opts machine.In
 	switch opts.VolumeDriver {
 	case "virtfs":
 		volumeType = VolumeTypeVirtfs
+	case "none":
+		volumeType = VolumeTypeNone
 	case "": // default driver
 		volumeType = VolumeTypeVirtfs
 	default:
