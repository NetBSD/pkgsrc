# $NetBSD: Makefile,v 1.8 2002/11/23 19:56:08 wiz Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.endif

.if ${MACHINE_ARCH} == "powerpc"
PLIST_SRC=	${.CURDIR}/PLIST.powerpc
.endif

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
