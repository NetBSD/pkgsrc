# $NetBSD: Makefile,v 1.1 2013/09/14 09:06:48 ryoon Exp $
#

DISTNAME=	luaposix-release-v31
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/:S/release-v//}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/luaposix/luaposix/archive/release-v31.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luaposix/luaposix
COMMENT=	POSIX library (including curses) for lua
LICENSE=	mit

FETCH_USING=	curl

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:build
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGNAME_NOREV}

post-install:
	cd ${DESTDIR}${PREFIX}/${LUA_CDIR} && \
	${LN} -fs ../../../share/${PKGNAME}/posix.lua && \
	${LN} -fs ../../../share/${PKGNAME}/curses.lua

.include "../../lang/lua/module.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
