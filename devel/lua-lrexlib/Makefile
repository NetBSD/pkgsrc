# $NetBSD: Makefile,v 1.5 2013/10/31 23:32:26 dholland Exp $

.include "../../devel/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://luaforge.net/projects/lrexlib
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
