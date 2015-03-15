# $NetBSD: Makefile,v 1.3 2015/03/15 20:03:24 hiramatsu Exp $

DISTNAME=	opencc-0.4.2
CATEGORIES=	converters chinese
MASTER_SITES=	http://dl.bintray.com/byvoid/opencc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencc.byvoid.com/
COMMENT=	Convertion between Traditional and Simplified Chinese
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	opencc.pc.in

USE_GCC_RUNTIME=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src

TEST_TARGET=	test

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_FILES.mandir=	doc/CMakeLists.txt
SUBST_SED.mandir=	-e 's,$${DIR_SHARE}/man,${PKGMANDIR},'

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
