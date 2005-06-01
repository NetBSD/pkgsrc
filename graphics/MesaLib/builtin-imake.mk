XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:02:54 jlam Exp $

/*
 * Check the value of BuildGLXLibrary for the presence of
 * MesaLib in the X11 distribution.
 */
builtin-test:
#if BuildGLXLibrary
	@echo yes
#else
	@echo no
#endif
