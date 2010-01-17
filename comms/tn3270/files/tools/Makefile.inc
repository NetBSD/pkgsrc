#	$NetBSD: Makefile.inc,v 1.1.1.1 2010/01/17 01:33:25 dholland Exp $
#	From NetBSD: Makefile.inc,v 1.8 2002/09/18 14:00:42 lukem Exp 

NOMAN=	# defined

HOST_CPPFLAGS+=-I${.CURDIR}/../../api
KBD= unix.kbd

.PATH: ${.CURDIR}/../../api

.if exists(${.CURDIR}/../../../Makefile.inc)
.include "${.CURDIR}/../../../Makefile.inc"
.endif
