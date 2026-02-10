# $NetBSD: Makefile,v 1.3 2026/02/10 08:10:27 wiz Exp $

DISTNAME=	stringtie-2.1.1
CATEGORIES=	biology
MASTER_SITES=	https://ccb.jhu.edu/software/stringtie/dl/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.ccb.jhu.edu/software/stringtie/
COMMENT=	Transcript assembly and quantification for RNA-seq
LICENSE=	mit

TEST_DEPENDS=	bash>0:../../shells/bash \
		curl>0:../../www/curl
TEST_TARGET=	test

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
BUILD_TARGET=	release

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stringtie ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
