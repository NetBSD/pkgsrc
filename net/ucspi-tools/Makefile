# $NetBSD: Makefile,v 1.1 2020/11/26 15:52:58 schmonz Exp $

DISTNAME=		ucspi-tools-1.6
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

.include "../../security/libressl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
