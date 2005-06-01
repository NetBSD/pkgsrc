XCOMM $NetBSD: builtin-imake.mk,v 1.1 2005/06/01 18:03:23 jlam Exp $

/*
 * Check the value of BuildExpatLibrary for the presence of
 * expat in the X11 distribution.
 */
builtin-test:
#if BuildExpatLibrary
	@echo yes
#else
	@echo no
#endif
