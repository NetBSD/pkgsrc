# $NetBSD: Makefile,v 1.26 2020/05/20 06:09:09 rillig Exp $
#

DISTNAME=		tvision-0.8
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/c++/}

PATCHFILES=		tvision-0.8-freebsd-patches-20040910.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sigala.it/sergio/tvision/
COMMENT=		Turbo Vision C++ CUI library for UNIX

MAKE_JOBS_SAFE=		no
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		YES

# puzzle.cc: In member function 'virtual void TPuzzleView::draw()':
# puzzle.cc:134:75: error: array subscript has type 'char' [-Werror=char-subscripts]
#                  buf.moveStr( (short)(j*3), tmp, color[map[board[i][j]-'A']]);
#                                                                            ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
