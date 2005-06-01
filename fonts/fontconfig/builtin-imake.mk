XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:48 jlam Exp $

/*
 * Check the value of BuildFontconfigLibrary for the presence of
 * fontconfig in the X11 distribution.
 */
builtin-test:
#if BuildFontconfigLibrary
	@echo yes
#else
	@echo no
#endif
