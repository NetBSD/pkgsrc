# $NetBSD: Makefile,v 1.4 2002/09/08 09:59:51 schmonz Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.endif

COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

ONLY_FOR_PLATFORM+= NetBSD-*-arm Linux-*-arm

.include "../../lang/blackdown-jre13/Makefile.common"
.include "../../mk/bsd.pkg.mk"
