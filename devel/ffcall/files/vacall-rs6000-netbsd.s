	.file	"vacall-rs6000.c"
gcc2_compiled.:
	.section	".text"
	.align 2
	.globl __vacall_r
	.type	 __vacall_r,@function
__vacall_r:
	stwu 1,-208(1)
	mflr 0
	stw 0,212(1)
	stw 3,152(1)
	stw 4,156(1)
	stw 5,160(1)
	stw 6,164(1)
	stw 7,168(1)
	stw 8,172(1)
	stw 9,176(1)
	stw 10,180(1)
	stfd 1,48(1)
	stfd 2,56(1)
	stfd 3,64(1)
	stfd 4,72(1)
	stfd 5,80(1)
	stfd 6,88(1)
	stfd 7,96(1)
	stfd 8,104(1)
	li 9,0
	stw 9,8(1)
	addi 0,1,152
	stw 0,12(1)
	addi 0,1,216
	stw 0,184(1)
	stw 9,188(1)
	stw 9,16(1)
	stw 9,20(1)
	addi 0,1,48
	stw 0,40(1)
	lwz 9,0(13)
	lwz 3,4(13)
	addi 4,1,8
	mtlr 9
	blrl
	lwz 0,20(1)
	cmpwi 0,0,0
	bc 12,2,.L4
	cmpwi 0,0,1
	bc 12,2,.L42
	lwz 0,20(1)
	cmpwi 0,0,2
	bc 4,2,.L7
	lbz 0,32(1)
	extsb 3,0
	b .L4
.L7:
	lwz 0,20(1)
	cmpwi 0,0,3
	bc 4,2,.L9
.L42:
	lbz 3,32(1)
	b .L4
.L9:
	lwz 0,20(1)
	cmpwi 0,0,4
	bc 4,2,.L11
	lha 3,32(1)
	b .L4
.L11:
	lwz 0,20(1)
	cmpwi 0,0,5
	bc 4,2,.L13
	lhz 3,32(1)
	b .L4
.L13:
	lwz 0,20(1)
	cmpwi 0,0,6
	bc 12,2,.L43
	lwz 0,20(1)
	cmpwi 0,0,7
	bc 12,2,.L43
	lwz 0,20(1)
	cmpwi 0,0,8
	bc 12,2,.L43
	lwz 0,20(1)
	cmpwi 0,0,9
	bc 12,2,.L43
	lwz 9,20(1)
	addi 9,9,-10
	cmplwi 0,9,1
	bc 12,1,.L23
	lwz 3,32(1)
	lwz 4,36(1)
	b .L4
.L23:
	lwz 0,20(1)
	cmpwi 0,0,12
	bc 4,2,.L25
	lfs 1,32(1)
	b .L4
.L25:
	lwz 0,20(1)
	cmpwi 0,0,13
	bc 4,2,.L27
	lfd 1,32(1)
	b .L4
.L27:
	lwz 0,20(1)
	cmpwi 0,0,14
	bc 4,2,.L29
.L43:
	lwz 3,32(1)
	b .L4
.L29:
	lwz 0,20(1)
	cmpwi 0,0,15
	bc 4,2,.L4
	lwz 0,8(1)
	andi. 9,0,1
	bc 12,2,.L32
	lwz 3,16(1)
	b .L4
.L32:
	lwz 0,8(1)
	andi. 9,0,1024
	bc 12,2,.L4
	lwz 0,24(1)
	cmpwi 0,0,1
	bc 4,2,.L35
	lwz 9,16(1)
	lbz 3,0(9)
	b .L4
.L35:
	lwz 0,24(1)
	cmpwi 0,0,2
	bc 4,2,.L37
	lwz 9,16(1)
	lhz 3,0(9)
	b .L4
.L37:
	lwz 0,24(1)
	cmpwi 0,0,4
	bc 4,2,.L39
	lwz 9,16(1)
	lwz 3,0(9)
	b .L4
.L39:
	lwz 0,24(1)
	cmpwi 0,0,8
	bc 4,2,.L4
	lwz 9,16(1)
	lwz 3,0(9)
	lwz 4,4(9)
.L4:
	lwz 0,212(1)
	mtlr 0
	la 1,208(1)
	blr
.Lfe1:
	.size	 __vacall_r,.Lfe1-__vacall_r
	.ident	"GCC: (GNU) 2.95.2 19991024 (release/franzo)"
