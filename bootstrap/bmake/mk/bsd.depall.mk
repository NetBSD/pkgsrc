#	$NetBSD: bsd.depall.mk,v 1.1.1.1 2004/03/11 13:04:17 grant Exp $

dependall: realdepend .MAKE
	@cd ${.CURDIR}; \
	${MAKE} realall
