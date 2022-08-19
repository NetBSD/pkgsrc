# $NetBSD: Makefile,v 1.10 2022/08/19 13:48:25 tnn Exp $

DISTNAME=	codebrowser-2.1.20220614
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_TAG=	ff3846d2addc75d1077435a3df87fd7606e54485

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://code.woboq.org/
COMMENT=	Code analysis tool
LICENSE=	cc-by-nc-sa-v3.0-license

USE_CMAKE=	yes
CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LLVM_CONFIG_PATH:Q} \
		-DCMAKE_BUILD_TYPE=Release

USE_TOOLS+=	pax
USE_LANGUAGES=	c c++11

INSTALLATION_DIRS+=	bin share/woboq_codebrowser

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/generator/codebrowser_generator ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indexgenerator/codebrowser_indexgenerator ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/data && pax -rwpp . ${DESTDIR}${PREFIX}/share/woboq_codebrowser

.include "../../lang/clang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
