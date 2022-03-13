# $NetBSD: Makefile,v 1.5 2022/03/13 06:59:19 mef Exp $

VERSION=	1.1.3
GITHUB_PROJECT=	OpenCC
GITHUB_TAG=	ver.${VERSION}
DISTNAME=	OpenCC-ver.${VERSION}
PKGNAME=	${DISTNAME:S/OpenCC-ver./opencc-/}
CATEGORIES=	converters chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=BYVoid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencc.byvoid.com/
COMMENT=	Convertion between Traditional and Simplified Chinese
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME} # GitHub rule is not relevant for this.

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	opencc.pc.in

USE_GCC_RUNTIME=	yes

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src

TEST_TARGET=	test

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
