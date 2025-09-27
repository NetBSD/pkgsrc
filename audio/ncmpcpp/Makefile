# $NetBSD: Makefile,v 1.34 2025/09/27 09:57:06 wiz Exp $

DISTNAME=	ncmpcpp-0.10.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncmpcpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rybczak.net/ncmpcpp/
COMMENT=	Featureful (n)curses based musicpd client inspired by ncmpc
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake autoreconf pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}

# Do not look for boost_system library.
CONFIGURE_ENV+=	boost_cv_lib_system=yes

USE_CURSES=	getmouse wide

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
