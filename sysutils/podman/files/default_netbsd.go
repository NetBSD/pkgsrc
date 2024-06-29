package config

func getDefaultCgroupsMode() string {
	return "enabled"
}

// In theory, FreeBSD should be able to use shm locks but in practice,
// this causes cryptic error messages from the kernel that look like:
//
//	comm podman pid 90813: handling rb error 22
//
// These seem to be related to fork/exec code paths. Fall back to
// file-based locks.
func getDefaultLockType() string {
	return "file"
}

func getLibpodTmpDir() string {
	return "@VARBASE@/run/libpod"
}

// getDefaultMachineVolumes returns default mounted volumes (possibly with env vars, which will be expanded)
func getDefaultMachineVolumes() []string {
	/* XXXTNN this doesn't work yet. Needs virtio-9p in QEMU */
//	return []string{"$HOME:$HOME"}
	return []string{}
}

func getDefaultComposeProviders() []string {
	return defaultUnixComposeProviders
}
