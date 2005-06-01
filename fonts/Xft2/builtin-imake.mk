XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:48 jlam Exp $

/*
 * Check the value of BuildXftLibrary for the presence of
 * Xft2 in the X11 distribution.
 */
builtin-test:
#if BuildXftLibrary
	@echo yes
#else
	@echo no
#endif
