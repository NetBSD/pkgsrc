$NetBSD: patch-.._github.com_awnumar_memcall@v0.1.2_memcall__netbsd.go,v 1.1 2024/05/14 22:38:57 wiz Exp $

Add NetBSD support.
https://github.com/awnumar/memcall/pull/10

--- ../github.com/awnumar/memcall@v0.1.2/memcall_netbsd.go.orig	2024-05-14 22:02:31.351934223 +0000
+++ ../github.com/awnumar/memcall@v0.1.2/memcall_netbsd.go
@@ -0,0 +1,94 @@
+//go:build netbsd
+// +build netbsd
+
+package memcall
+
+import (
+	"errors"
+	"fmt"
+
+	"golang.org/x/sys/unix"
+)
+
+// Lock is a wrapper for mlock(2), with extra precautions.
+func Lock(b []byte) error {
+	// Call mlock.
+	if err := unix.Mlock(b); err != nil {
+		return fmt.Errorf("<memcall> could not acquire lock on %p, limit reached? [Err: %s]", _getStartPtr(b), err)
+	}
+
+	return nil
+}
+
+// Unlock is a wrapper for munlock(2).
+func Unlock(b []byte) error {
+	if err := unix.Munlock(b); err != nil {
+		return fmt.Errorf("<memcall> could not free lock on %p [Err: %s]", _getStartPtr(b), err)
+	}
+
+	return nil
+}
+
+// Alloc allocates a byte slice of length n and returns it.
+func Alloc(n int) ([]byte, error) {
+	// Allocate the memory.
+	b, err := unix.Mmap(-1, 0, n, unix.PROT_READ|unix.PROT_WRITE, unix.MAP_PRIVATE|unix.MAP_ANON)
+	if err != nil {
+		return nil, fmt.Errorf("<memcall> could not allocate [Err: %s]", err)
+	}
+
+	// Wipe it just in case there is some remnant data.
+	wipe(b)
+
+	// Return the allocated memory.
+	return b, nil
+}
+
+// Free deallocates the byte slice specified.
+func Free(b []byte) error {
+	// Make the memory region readable and writable.
+	if err := Protect(b, ReadWrite()); err != nil {
+		return err
+	}
+
+	// Wipe the memory region in case of remnant data.
+	wipe(b)
+
+	// Free the memory back to the kernel.
+	if err := unix.Munmap(b); err != nil {
+		return fmt.Errorf("<memcall> could not deallocate %p [Err: %s]", _getStartPtr(b), err)
+	}
+
+	return nil
+}
+
+// Protect modifies the protection state for a specified byte slice.
+func Protect(b []byte, mpf MemoryProtectionFlag) error {
+	var prot int
+	if mpf.flag == ReadWrite().flag {
+		prot = unix.PROT_READ | unix.PROT_WRITE
+	} else if mpf.flag == ReadOnly().flag {
+		prot = unix.PROT_READ
+	} else if mpf.flag == NoAccess().flag {
+		prot = unix.PROT_NONE
+	} else {
+		return errors.New(ErrInvalidFlag)
+	}
+
+	// Change the protection value of the byte slice.
+	if err := unix.Mprotect(b, prot); err != nil {
+		return fmt.Errorf("<memcall> could not set %d on %p [Err: %s]", prot, _getStartPtr(b), err)
+	}
+
+	return nil
+}
+
+// DisableCoreDumps disables core dumps on Unix systems.
+func DisableCoreDumps() error {
+	// Disable core dumps.
+	if err := unix.Setrlimit(unix.RLIMIT_CORE, &unix.Rlimit{Cur: 0, Max: 0}); err != nil {
+		return fmt.Errorf("<memcall> could not set rlimit [Err: %s]", err)
+	}
+
+	return nil
+}
