# $NetBSD: Makefile,v 1.22 2024/08/25 06:19:09 wiz Exp $

DISTNAME=	neix-0.1.5
PKGREVISION=	9
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=qw3rtty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomschwarz/neix/
COMMENT=	RSS/Atom feed reader for your terminal
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

USE_CXX_FEATURES+=	regex

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	CMakeLists.txt
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../devel/ncurses/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
