# $NetBSD: Makefile,v 1.17 2023/10/24 22:08:15 wiz Exp $

DISTNAME=	rtunes-0.8
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.nazgul.ch/dev_rtunes.html
COMMENT=	Stream audio to an AirTunes device
LICENSE=	modified-bsd

BUILD_DIRS=	rtunes
INSTALL_DIRS=	rtunes

MAKE_FLAGS+=	NOGCCERROR=1
MAKE_FLAGS+=	NOCLANGERROR=1

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
