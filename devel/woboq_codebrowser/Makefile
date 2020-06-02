# $NetBSD: Makefile,v 1.5 2020/06/02 08:23:42 adam Exp $

DISTNAME=	woboq_codebrowser-2.1
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=woboq/}
GITHUB_TAG=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	woboq_codebrowser

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
