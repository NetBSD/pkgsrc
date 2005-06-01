XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:55 jlam Exp $

/*
 * Check the value of BuildFreetype2Library for the presence of
 * freetype2 in the X11 distribution.
 */
builtin-test:
#if BuildFreetype2Library
	@echo yes
#else
	@echo no
#endif
