#  cpuburn-1.4:	 burnK6	  CPU Loading Utility
#  Copyright 1999  Robert J. Redelmeier.  All Right Reserved
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
	fldpi
	fldl	rt
	fstpl	-24(%ebp)
	fldl	e
	fstpl	-32(%ebp)
	movl	half, %edx
	movl	%edx, -8(%ebp)
after_check:
	xorl	%eax, %eax
	movl	%eax, %ebx
	lea	-1(%eax), %esi
	movl	$400000000, %ecx  
	movl	%ecx, -4(%ebp)	 
.align	32,  0x90
crunch:				
	fldl	8-24(%ebp,%esi,8)	# CALC BLOCK
	fmull	8-32(%ebp,%esi,8)
	addl	half+9(%esi,%esi,8), %edx
	jnz	. + 2
	faddp	
	fldl	8-24(%ebp,%esi,8)
	decl	%ebx
	subl	half+9(%esi,%esi,8), %edx
	jmp	. + 2
	fmull	8-32(%ebp,%esi,8)
	incl	%ebx
	decl	8-4(%ebp,%esi,8)
	fsubp	
	jnz	crunch			# time for testing ?

	test	%ebx, %ebx		# TEST BLOCK
	jnz	int_exit
	cmpl	half, %edx
	jnz	int_exit
	fldpi
	fcomp	%st(1)
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
half:	.long 0x7fffffff,0
e:	.long 0xffffffff,0x3fdfffff
rt:	.long 0xffffffff,0x3fefffff


