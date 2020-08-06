# $NetBSD: Makefile,v 1.1 2020/08/06 23:17:57 joerg Exp $

DISTNAME=	vstruct-2.1.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=ToxicFrog/}
GITHUB_PROJECT=	vstruct
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ToxicFrog/vstruct/
COMMENT=	Binary data manipulation function
LICENSE=	mit

NO_BUILD=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}/vstruct/ast ${LUA_LDIR}/vstruct/io

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/vstruct
	${INSTALL_DATA} ${WRKSRC}/ast/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/vstruct/ast
	${INSTALL_DATA} ${WRKSRC}/io/*.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/vstruct/io

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
