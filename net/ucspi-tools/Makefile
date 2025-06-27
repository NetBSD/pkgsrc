# $NetBSD: Makefile,v 1.10 2025/06/27 17:25:00 schmonz Exp $

DISTNAME=		ucspi-tools-1.7
PKGREVISION=		2
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_GITHUB:=younix/}
GITHUB_PROJECT=		ucspi
GITHUB_TAG=		9435993f47af23a98464beee872e412aec295e5c

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/younix/ucspi/
COMMENT=		SOCKS proxy and TLS support for UCSPI
LICENSE=		isc

# strlcpy
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

# NI_MAXHOST
CFLAGS.SunOS+=		-D__EXTENSIONS__
LDFLAGS.SunOS+=		-lsocket

USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		GNUmakefile

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}

TEST_DEPENDS+=		oksh-[0-9]*:../../shells/oksh
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
