# $NetBSD: Makefile,v 1.20 2024/05/29 16:34:07 adam Exp $

DISTNAME=	neix-0.1.5
PKGREVISION=	9
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=qw3rtty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomschwarz/neix/
COMMENT=	RSS/Atom feed reader for your terminal
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

USE_CXX_FEATURES+=	regex

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	CMakeLists.txt
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
