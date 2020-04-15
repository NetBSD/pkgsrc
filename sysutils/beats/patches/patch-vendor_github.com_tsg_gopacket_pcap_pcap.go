$NetBSD: patch-vendor_github.com_tsg_gopacket_pcap_pcap.go,v 1.2 2020/04/15 13:00:55 jperkin Exp $

Just require pcap, fixes NetBSD.
Pull in upstream patch to fix newer cgo syntax.

--- vendor/github.com/tsg/gopacket/pcap/pcap.go.orig	2020-03-05 13:27:52.000000000 +0000
+++ vendor/github.com/tsg/gopacket/pcap/pcap.go
@@ -8,14 +8,7 @@
 package pcap
 
 /*
-#cgo linux LDFLAGS: -lpcap
-#cgo freebsd LDFLAGS: -lpcap
-#cgo openbsd LDFLAGS: -lpcap
-#cgo darwin LDFLAGS: -lpcap
-#cgo solaris LDFLAGS: -lpcap
-#cgo windows CFLAGS: -I C:/WpdPack/Include
-#cgo windows,386 LDFLAGS: -L C:/WpdPack/Lib -lwpcap
-#cgo windows,amd64 LDFLAGS: -L C:/WpdPack/Lib/x64 -lwpcap
+#cgo LDFLAGS: -lpcap
 #include <stdlib.h>
 #include <pcap.h>
 
@@ -170,7 +163,7 @@ type InterfaceAddress struct {
 // BPF is a compiled filter program, useful for offline packet matching.
 type BPF struct {
 	orig string
-	bpf  _Ctype_struct_bpf_program // takes a finalizer, not overriden by outsiders
+	bpf  C.struct_bpf_program // takes a finalizer, not overriden by outsiders
 }
 
 // BlockForever, when passed into OpenLive/SetTimeout, causes it to block forever
@@ -382,7 +375,7 @@ func (p *Handle) Error() error {
 
 // Stats returns statistics on the underlying pcap handle.
 func (p *Handle) Stats() (stat *Stats, err error) {
-	var cstats _Ctype_struct_pcap_stat
+	var cstats C.struct_pcap_stat
 	if -1 == C.pcap_stats(p.cptr, &cstats) {
 		return nil, p.Error()
 	}
@@ -443,7 +436,7 @@ func (p *Handle) SetBPFFilter(expr strin
 		}
 	}
 
-	var bpf _Ctype_struct_bpf_program
+	var bpf C.struct_bpf_program
 	cexpr := C.CString(expr)
 	defer C.free(unsafe.Pointer(cexpr))
 
@@ -486,7 +479,7 @@ func (b *BPF) String() string {
 }
 
 // BPF returns the compiled BPF program.
-func (b *BPF) BPF() _Ctype_struct_bpf_program {
+func (b *BPF) BPF() C.struct_bpf_program {
 	return b.bpf
 }
 
@@ -549,10 +542,10 @@ func FindAllDevs() (ifs []Interface, err
 	return
 }
 
-func findalladdresses(addresses *_Ctype_struct_pcap_addr) (retval []InterfaceAddress) {
+func findalladdresses(addresses *C.struct_pcap_addr) (retval []InterfaceAddress) {
 	// TODO - make it support more than IPv4 and IPv6?
 	retval = make([]InterfaceAddress, 0, 1)
-	for curaddr := addresses; curaddr != nil; curaddr = (*_Ctype_struct_pcap_addr)(curaddr.next) {
+	for curaddr := addresses; curaddr != nil; curaddr = (*C.struct_pcap_addr)(curaddr.next) {
 		var a InterfaceAddress
 		var err error
 		// In case of a tun device on Linux the link layer has no curaddr.addr.
@@ -818,7 +811,7 @@ func (h *Handle) NewDumper(file string)
 // Writes a packet to the file. The return values of ReadPacketData
 // can be passed to this function as arguments.
 func (d *Dumper) WritePacketData(data []byte, ci gopacket.CaptureInfo) (err error) {
-	var pkthdr _Ctype_struct_pcap_pkthdr
+	var pkthdr C.struct_pcap_pkthdr
 	pkthdr.caplen = C.bpf_u_int32(ci.CaptureLength)
 	pkthdr.len = C.bpf_u_int32(ci.Length)
 
