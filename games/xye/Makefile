# $NetBSD: Makefile,v 1.21 2023/11/12 13:21:46 wiz Exp $
#

DISTNAME=	xye-0.12.1
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xye/0.12.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xye.sourceforge.net/
COMMENT=	Kye clone

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc
USE_LANGUAGES=		c c++

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

SUBST_CLASSES+=		crlf
SUBST_MESSAGE.crlf=	stripping EOL CR
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	*/*
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

# src/xye.cpp: In static member function 'static void game::start(bool)':
# src/xye.cpp:1225:23: error: array subscript has type 'char' [-Werror=char-subscripts]
#              sq=&grid[i][j];
#                        ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
