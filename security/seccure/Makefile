# $NetBSD: Makefile,v 1.5 2014/01/01 11:52:34 wiz Exp $

DISTNAME=	seccure-0.4
PKGREVISION=	3
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
