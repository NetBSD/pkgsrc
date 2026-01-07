# $NetBSD: Makefile,v 1.9 2026/01/07 08:43:19 wiz Exp $

.include "../../devel/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
PKGREVISION=	3
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@NetBSD.org
COMMENT=	Regexp libraries for Lua programming language
LICENSE=	mit

APIs=		pcre posix onig

.for i in ${APIs}
DEPENDS+=	${LUA_PKGPREFIX}-lrexlib-${i}-${VERSION}{,nb*}:../../devel/lua-lrexlib-${i}
.endfor

DESCR_SRC=		${.CURDIR}/DESCR.common

META_PACKAGE=		yes

.include "../../lang/lua/luaversion.mk" # for LUA_PKGPREFIX
.include "../../mk/bsd.pkg.mk"
