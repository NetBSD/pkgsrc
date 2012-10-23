# $NetBSD: Makefile,v 1.4 2012/10/23 18:16:57 asau Exp $

DISTNAME=	seccure-0.4
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/seccure/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://point-at-infinity.org/seccure/
COMMENT=	SECCURE Elliptic Curve Crypto Utility for Reliable Encryption
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
