# $NetBSD: Makefile,v 1.6 2020/11/30 12:41:41 nia Exp $

DISTNAME=		ucspi-tools-1.6
PKGREVISION=		2
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_GITHUB:=younix/}
GITHUB_PROJECT=		ucspi
GITHUB_TAG=		1aa21e6bd85ec45a6bce9b570548b6f4a5b1a9ed

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/younix/ucspi/
COMMENT=		SOCKS proxy and TLS support for UCSPI
LICENSE=		isc

# strlcpy
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		GNUmakefile

WRKSRC=			${WRKDIR}/ucspi-${GITHUB_TAG}

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
