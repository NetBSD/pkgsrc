#  cpuburn-1.4:	 burnK7	  CPU Loading Utility
#  Copyright 2000  Robert J. Redelmeier.  All Right Reserved
#  Licensed under GNU General Public Licence 2.0.  No warrantee.
#  *** USE AT YOUR OWN RISK ***

.text 
#ifdef WINDOWS
.globl _main
_main:
#else
.globl _start
_start:
#endif
	finit
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-32, %ebp
	subl	$96, %esp
	fldl	rt
	fstpl	-24(%ebp)
	fldl	e
	fstpl	-32(%ebp)
	fldpi
	fldpi
	xorl	%eax, %eax
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	half, %edx
	lea	-1(%eax), %esi
	movl	%eax, -12(%ebp)
	movl	%edx, -8(%ebp)
after_check:
	movl	$850000000, -4(%ebp)  
.align	32,  0x90
crunch:				
	fxch				# CALC BLOCK
	fldl	8-24(%ebp,%esi,8)	# 17 instr / 6.0 cycles
	addl	half+9(%esi,%esi,8), %edx
	fmull	8-32(%ebp,%esi,8)
	faddp	
	decl	%ecx
	fldl	8-24(%ebp,%esi,8)
	decl	%ebx
	incl	8-12(%ebp,%esi,8)
	subl	half+9(%esi,%esi,8), %edx
	incl	%ecx
	fmull	8-32(%ebp,%esi,8)
	incl	%ebx
	decl	8-4(%ebp,%esi,8)
	jmp	. + 2
	fsubp	%st, %st(2)
	jnz	crunch			# time for testing ?

	test	%ebx, %ebx		# TEST BLOCK
	jnz	int_exit
	test	%ecx, %ecx
	jnz	int_exit
	cmpl	half, %edx
	jnz	int_exit
	fcom	%st(1)
	fstsw	%ax
	sahf
	jz	after_check
	decl	%ebx
int_exit:
	decl	%ebx
	addl	$96,  %esp
	popl	%ebp
	movl	$1, %eax
#ifdef WINDOWS
	ret
#else
	push	%ebx
	push	%eax
	int	$0x80
#endif
.align 32,0
	.fill 64
half:	.long 0x7fffffff,0
e:	.long 0xffffffff,0x3fdfffff
rt:	.long 0xffffffff,0x3fefffff


