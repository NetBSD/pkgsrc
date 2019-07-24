# $NetBSD: Makefile,v 1.2 2019/07/24 17:43:02 nia Exp $

DISTNAME=	kakoune-2019.07.01
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
USE_LANGUAGES=	c c++17

# C++17
GCC_REQD+=	7

FAKE_NCURSES=	yes

MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	gzip_man=no

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
