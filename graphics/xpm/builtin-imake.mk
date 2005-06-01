XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:58 jlam Exp $

/*
 * Check the value of NormalLibXpm for the presence of Xpm
 * in the X11 distribution.
 */
builtin-test:
#if NormalLibXpm
	@echo yes
#else
	@echo no
#endif
