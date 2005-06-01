XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:56 jlam Exp $

/*
 * Check the value of BuildGLULibrary for the presence of
 * glu in the X11 distribution.
 */
builtin-test:
#if BuildGLULibrary
	@echo yes
#else
	@echo no
#endif
