# $NetBSD: Makefile,v 1.1 2023/08/12 14:58:35 bacon Exp $

DISTNAME=	stringtie-2.1.1
CATEGORIES=	biology
MASTER_SITES=	http://ccb.jhu.edu/software/stringtie/dl/

OWNER=		bacon@NetBSD.org
HOMEPAGE=	http://www.ccb.jhu.edu/software/stringtie/
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
