# $NetBSD: Makefile,v 1.5 2002/10/12 21:19:58 jschauma Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.elif ${MACHINE_ARCH} == "powerpc"
DISTNAME:=	${DISTNAME}.bin
.endif

COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

ONLY_FOR_PLATFORM+= NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
