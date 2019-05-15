$NetBSD: patch-.._.._pkg_term_termios_termios__solaris.go,v 1.1 2019/05/15 18:03:34 jperkin Exp $

Apply SunOS fix from https://github.com/pkg/term/pull/41

--- ../../pkg/term/termios/termios_solaris.go.orig	2019-04-25 03:19:22.118815385 +0000
+++ ../../pkg/term/termios/termios_solaris.go
@@ -31,13 +31,13 @@ const FIORDCHK = C.FIORDCHK
 // Tcgetattr gets the current serial port settings.
 func Tcgetattr(fd uintptr, argp *syscall.Termios) error {
 	termios, err := unix.IoctlGetTermios(int(fd), unix.TCGETS)
-	*argp = syscall.Termios(*termios)
+	*argp = *(tiosToSyscall(termios))
 	return err
 }
 
 // Tcsetattr sets the current serial port settings.
 func Tcsetattr(fd, action uintptr, argp *syscall.Termios) error {
-	return unix.IoctlSetTermios(int(fd), int(action), (*unix.Termios)(argp))
+	return unix.IoctlSetTermios(int(fd), uint(action), tiosToUnix(argp))
 }
 
 // Tcsendbreak transmits a continuous stream of zero-valued bits for a specific
@@ -77,26 +77,50 @@ func Tiocoutq(fd uintptr, argp *int) err
 
 // Cfgetispeed returns the input baud rate stored in the termios structure.
 func Cfgetispeed(attr *syscall.Termios) uint32 {
-	solTermios := (*unix.Termios)(attr)
+	solTermios := tiosToUnix(attr)
 	return uint32(C.cfgetispeed((*C.termios_t)(unsafe.Pointer(solTermios))))
 }
 
 // Cfsetispeed sets the input baud rate stored in the termios structure.
 func Cfsetispeed(attr *syscall.Termios, speed uintptr) error {
-	solTermios := (*unix.Termios)(attr)
+	solTermios := tiosToUnix(attr)
 	_, err := C.cfsetispeed((*C.termios_t)(unsafe.Pointer(solTermios)), C.speed_t(speed))
 	return err
 }
 
 // Cfgetospeed returns the output baud rate stored in the termios structure.
 func Cfgetospeed(attr *syscall.Termios) uint32 {
-	solTermios := (*unix.Termios)(attr)
+	solTermios := tiosToUnix(attr)
 	return uint32(C.cfgetospeed((*C.termios_t)(unsafe.Pointer(solTermios))))
 }
 
 // Cfsetospeed sets the output baud rate stored in the termios structure.
 func Cfsetospeed(attr *syscall.Termios, speed uintptr) error {
-	solTermios := (*unix.Termios)(attr)
+	solTermios := tiosToUnix(attr)
 	_, err := C.cfsetospeed((*C.termios_t)(unsafe.Pointer(solTermios)), C.speed_t(speed))
 	return err
 }
+
+// tiosToUnix copies a syscall.Termios to a x/sys/unix.Termios.
+// This is needed since type conversions between the two fail due to
+// more recent x/sys/unix.Termios renaming the padding field.
+func tiosToUnix(st *syscall.Termios) *unix.Termios {
+	return &unix.Termios{
+		Iflag:  st.Iflag,
+		Oflag:  st.Oflag,
+		Cflag:  st.Cflag,
+		Lflag:  st.Lflag,
+		Cc:     st.Cc,
+	}
+}
+
+// tiosToSyscall copies a x/sys/unix.Termios to a syscall.Termios.
+func tiosToSyscall(ut *unix.Termios) *syscall.Termios {
+	return &syscall.Termios{
+		Iflag:  ut.Iflag,
+		Oflag:  ut.Oflag,
+		Cflag:  ut.Cflag,
+		Lflag:  ut.Lflag,
+		Cc:     ut.Cc,
+	}
+}
