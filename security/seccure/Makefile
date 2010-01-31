# $NetBSD: Makefile,v 1.2 2010/01/31 23:24:24 joerg Exp $

DISTNAME=	seccure-0.4
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/seccure/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://point-at-infinity.org/seccure/
COMMENT=	SECCURE Elliptic Curve Crypto Utility for Reliable Encryption
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	-Wl,-rpath,${PREFIX}/lib

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
