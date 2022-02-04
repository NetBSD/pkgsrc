# $NetBSD: Makefile,v 1.8 2022/02/04 09:03:54 pin Exp $

DISTNAME=	neix-0.1.5
PKGREVISION=	2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_GITHUB:=qw3rtty/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/tomschwarz/neix/
COMMENT=	RSS/Atom feed reader for your terminal
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	CMakeLists.txt
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
