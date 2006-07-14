#	$NetBSD: bsd.depall.mk,v 1.1.1.1 2006/07/14 23:13:00 jlam Exp $

dependall: realdepend .MAKE
	@cd ${.CURDIR}; \
	${MAKE} realall
