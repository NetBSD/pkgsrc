# $NetBSD: Makefile,v 1.25 2024/05/29 16:31:23 adam Exp $

DISTNAME=	ncmpcpp-0.9.2
PKGREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	https://rybczak.net/ncmpcpp/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rybczak.net/ncmpcpp/
COMMENT=	Featureful (n)curses based musicpd client inspired by ncmpc
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
USE_CURSES=	wide getmouse

USE_CXX_FEATURES+=	c++14

.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} != "ncurses"
CONFIGURE_ENV+=	ncursesw_CFLAGS="-I${BUILDLINK_PREFIX.curses}/include"
CONFIGURE_ENV+=	ncursesw_LIBS="${BUILDLINK_LDADD.curses}"
.endif

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
