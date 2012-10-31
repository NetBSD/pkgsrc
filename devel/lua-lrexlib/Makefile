# $NetBSD: Makefile,v 1.4 2012/10/31 11:17:26 asau Exp $

.include "../../devel/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://luaforge.net/projects/lrexlib
COMMENT=	Regexp libraries for Lua programming language
LICENSE=	mit

APIs=		pcre posix onig

.for i in ${APIs}
DEPENDS+=	lua-lrexlib-${i}-${VERSION}{,nb*}:../../devel/lua-lrexlib-${i}
.endfor

DESCR_SRC=		${.CURDIR}/DESCR.common

META_PACKAGE=		yes

.include "../../mk/bsd.pkg.mk"
