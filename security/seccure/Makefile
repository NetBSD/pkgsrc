# $NetBSD: Makefile,v 1.1.1.1 2009/12/14 08:00:05 agc Exp $

DISTNAME=	seccure-0.4
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/seccure/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://point-at-infinity.org/seccure/
COMMENT=	SECCURE Elliptic Curve Crypto Utility for Reliable Encryption
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
