#  cpuburn-1.4:	 burnMMX   Chipset/DRAM Loading Utility
#  Copyright 2000  Robert J. Redelmeier.  All Right Reserved
#  Licensed under GNU General Public Licence 2.0.  No warrantee.
#  *** USE AT YOUR OWN RISK ***
 
.text
#ifdef WINDOWS
.globl _main
_main:
	movl	4(%esp),%eax
	movl	$6, %ecx	# default f = 64 kB
	subl	$1, %eax	# is a param given? 
	jz	no_size

	movl	8(%esp),%eax	# address of strings
	movl	4(%eax),%eax	# address of first paramater
	movzb	(%eax),%ecx	# first parameter - a byte
no_size:
	subl	$12, %esp	# stack space
#else
.globl _start
_start:
	subl	$12, %esp
	movl	20(%esp), %eax
	movl	$6, %ecx	# default f = 64 kB
	testl	%eax, %eax	# is a param given? 
	jz	no_size
	movl	(%eax), %ecx
no_size:
#endif			     
	emms
	movq	rt, %mm0
	decl	%ecx		
	andl	$15, %ecx	# mask off ASCII bits
	movl	$256, %eax
	shll	%cl, %eax
	movl	%eax, 4(%esp)	# save blocksize
	movl	$256*1024, %eax
	shrl	%cl, %eax
	movl	%eax, 8(%esp)	# save count blks / 512 MB

	movl	4(%esp), %ecx	# initial fill of 2 cachelines
	shrl	$4, %ecx
	movl	$buffer, %edi
	xorl	%eax, %eax
	notl	%eax
more:
	movl	%eax, %edx	# qwords F-F-0-F , F-0-F-0 
	notl	%edx
	movl	%eax,  0(%edi)
	movl	%eax,  4(%edi)
	movl	%eax,  8(%edi)
	movl	%eax, 12(%edi)
	movl	%edx, 16(%edi)
	movl	%edx, 20(%edi)
	movl	%eax, 24(%edi)
	movl	%eax, 28(%edi)

	movl	%eax, 32(%edi)
	movl	%eax, 36(%edi)
	movl	%edx, 40(%edi)
	movl	%edx, 44(%edi)
	movl	%eax, 48(%edi)
	movl	%eax, 52(%edi)
	movl	%edx, 56(%edi)
	movl	%edx, 60(%edi)
	rcll	$1, %eax	# walking zero, 33 cycle
	leal	64(%edi), %edi	# odd inst to preserve CF
	decl	%ecx
	jnz	more

thrash:				# OUTER LOOP
	movl	8(%esp), %edx	#   reset count for 512 MB
mov_again:			
	movq	%mm0, %mm1
	movq	%mm0, %mm2
	movl	$buffer, %esi
	movl	$buf2, %edi
	movl	4(%esp), %ecx
	shll	$2, %ecx	# move block up
	addl	%ecx, %esi
	addl	%ecx, %edi
	negl	%ecx
.align 16, 0x90
0:				    # WORKLOOP 7 uops/ 3 clks in L1
	movq	0(%esi,%ecx),%mm7
	pmaddwd %mm0, %mm1
	pmaddwd %mm0, %mm2
	movq	%mm7, 0(%edi,%ecx)
	addl	$8, %ecx
	jnz	0b

	movl	$buffer + 32, %edi	# move block back
	movl	$buf2, %esi		# shifting by
	movl	4(%esp), %ecx		# one cacheline
	subl	$8, %ecx
	shll	$2, %ecx
	addl	%ecx, %esi
	addl	%ecx, %edi
	negl	%ecx
.align 16, 0x90
0:				   # second workloop
	movq	0(%esi,%ecx),%mm7
	pmaddwd %mm0, %mm1
	pmaddwd %mm0, %mm2
	movq	%mm7, 0(%edi,%ecx)
	addl	$8, %ecx
	jnz	0b

	movl	$buffer, %edi
	movsl			# replace last c line
	movsl
	movsl
	movsl
	movsl
	movsl
	movsl
	movsl
	decl	%edx		# do again for 512 MB.
	jnz	mov_again

	xorl	%ebx ,%ebx	# DATA CHECK
	decl	%ebx
	pcmpeqd %mm2, %mm1
	psrlq	$16, %mm1
	movd	%mm1, %eax
	incl	%eax
	jnz	error		# MMX calcs OK?

	decl	%ebx
	subl	$32, %edi	
	xorl	%ecx, %ecx
test:				# Check data (NOT optimized)
	mov	0(%edi,%ecx,4), %eax
	cmp	%eax, 4(%edi,%ecx,4)
	jnz	error
	incl	%ecx
	incl	%ecx
	cmpl	4(%esp), %ecx
	jc	test
	jmp	thrash

error:				# error abend
	emms
	movl	$1, %eax
#ifdef WINDOWS
	addl $12, %esp		# deallocate stack
	ret
#else
	push	%ebx
	push	%eax
	int	$0x80
#endif
rt:	.long	0x7fffffff, 0x7fffffff

.bss				# Data allocation
.align 32
.lcomm	buffer,	 32 <<20	# reduce both to 8 <<20 for only
.lcomm	buf2,	 32 <<20	# 16 MB virtual memory available

#
