#  cpuburn-1.4:	 burnP5	  CPU Loading Utility
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
	fldl	half
	fstpl	-24(%ebp)
	fldl	one
	fstl	-16(%ebp)
	fld	%st
	fld	%st
after_check:
	xorl	%eax, %eax
	movl	%eax, %ebx
	movl	$200000000, %ecx
.align	32,  0x90
				# MAIN LOOP  16 flops / 18 cycles
crunch:	   
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)

	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
 
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)

	fmull	-24(%ebp) 
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
	fmull	-24(%ebp)
	fxch	%st(1)
	faddl	-16(%ebp)
	fxch	%st(2)
 
	decl	%ecx
	jnz	crunch

	jmp	after_check
	addl	$96,  %esp	# never reached
	popl	%ebp		# no checking done
	movl	$1, %eax
#ifdef WINDOWS
	ret
#else
	int	$0x80
#endif
.align 32,0
half:	.long 0xffffffff,0x3fdfffff
one:	.long 0xffffffff,0x3fefffff

