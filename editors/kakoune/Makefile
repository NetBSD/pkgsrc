# $NetBSD: Makefile,v 1.10 2024/12/13 07:34:14 wiz Exp $

DISTNAME=	kakoune-2024.05.18
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=mawww/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kakoune.org/
COMMENT=	Experimental modal code editor
LICENSE=	unlicense

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++20

MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	CXXFLAGS-debug-no=
MAKE_FLAGS+=	PREFIX=${PREFIX}

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
