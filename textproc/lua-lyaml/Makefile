# $NetBSD: Makefile,v 1.7 2023/02/04 13:05:15 nia Exp $

DISTNAME=	lyaml-6.2.8
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=gvvaughan/}
GITHUB_PROJECT=	lyaml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://gvvaughan.github.io/lyaml/
COMMENT=	LibYAML binding for Lua
LICENSE=	mit

BUILD_DIRS=	ext/yaml

MAKE_FLAGS+=	PKGVERSION=${PKGVERSION}

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_CDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/lyaml

pre-build:
	${CP} -f ${FILESDIR}/Makefile ${WRKSRC}/ext/yaml/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/ext/yaml/yaml.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/yaml.so
	${INSTALL_DATA} ${WRKSRC}/lib/lyaml/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/lyaml
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}/README.md

.include "../../lang/lua/module.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
