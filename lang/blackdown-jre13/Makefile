# $NetBSD: Makefile,v 1.3 2002/09/05 05:14:01 schmonz Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${MACHINE_ARCH}
PKGNAME=	blackdown-jre13-1
.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.elif ${MACHINE_ARCH} == "powerpc"
DISTNAME=	${EXTNAME}-ppc
.endif

COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

ONLY_FOR_PLATFORM+= NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
