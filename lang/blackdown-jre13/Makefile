# $NetBSD: Makefile,v 1.7 2002/10/13 16:30:56 jschauma Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.endif

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
