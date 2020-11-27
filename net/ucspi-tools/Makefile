# $NetBSD: Makefile,v 1.2 2020/11/27 10:25:40 schmonz Exp $

DISTNAME=		ucspi-tools-1.6
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_GITHUB:=younix/}
GITHUB_PROJECT=		ucspi
GITHUB_TAG=		1aa21e6bd85ec45a6bce9b570548b6f4a5b1a9ed

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/younix/ucspi/
COMMENT=		SOCKS proxy and TLS support for UCSPI
LICENSE=		isc

USE_TOOLS+=		gmake pkg-config

WRKSRC=			${WRKDIR}/ucspi-${GITHUB_TAG}

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
