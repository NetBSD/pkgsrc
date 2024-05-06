# $NetBSD: Makefile,v 1.8 2024/05/06 08:40:24 jperkin Exp $

DISTNAME=	kakoune-2020.01.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=mawww/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kakoune.org/
COMMENT=	Experimental modal code editor
LICENSE=	unlicense

BUILD_DIRS=	src
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

CXXFLAGS+=	-D'KAK_BIN_PATH="${PREFIX}/bin/kak"'
MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	gzip_man=no

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
