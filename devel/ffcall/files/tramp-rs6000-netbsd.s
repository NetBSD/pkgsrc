/* Trampoline for rs6000 CPU with SysV.4 ABI */

/*
 * Copyright 1995-1999 Bruno Haible, <haible@clisp.cons.org>
 *
 * This is free software distributed under the GNU General Public Licence
 * described in the file COPYING. Contact the author if you don't have this
 * or can't live with it. There is ABSOLUTELY NO WARRANTY, explicit or implied,
 * on this software.
 */

/* Available registers: r0, r12, r11, r10, r9, r8, r7, r6, r5, r4, r3. */
/* However, r0 is special in that it cannot be used as a base register. */
/* And r3...r10 should not be clobbered because they contain the first 8
 * integer arguments to the function being called. 
 * Use r13 as it's the last possible register allocated with gcc and r11/12
 * get used during dynamic linkage.
 */

	.globl tramp
tramp:
/* Move <data> into register r13 */
	lis 13,0x7355
	ori 13,13,0x4711
/* Get <function> */
	lis 0,0xbabe
	ori 0,0,0xbec0
	mtctr 0
	bctr
