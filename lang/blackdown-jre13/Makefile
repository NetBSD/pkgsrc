# $NetBSD: Makefile,v 1.6 2002/10/13 07:41:58 jlam Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.elif ${MACHINE_ARCH} == "powerpc"
DISTNAME:=	${DISTNAME}.bin
.endif

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
