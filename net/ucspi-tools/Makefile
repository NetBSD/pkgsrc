# $NetBSD: Makefile,v 1.7 2021/07/12 21:32:49 schmonz Exp $

DISTNAME=		ucspi-tools-1.7
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_GITHUB:=younix/}
GITHUB_PROJECT=		ucspi
GITHUB_TAG=		329110310c71a08a942b4a36613b6db090df65f4

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/younix/ucspi/
COMMENT=		SOCKS proxy and TLS support for UCSPI
LICENSE=		isc

# strlcpy
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

USE_TOOLS+=		gmake pkg-config
MAKE_FILE=		GNUmakefile

INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}

TEST_DEPENDS+=		oksh-[0-9]*:../../shells/oksh
TEST_TARGET=		test

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
