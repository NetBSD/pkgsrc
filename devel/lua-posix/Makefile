# $NetBSD: Makefile,v 1.3 2014/01/27 08:10:24 obache Exp $
#

DISTNAME=	luaposix-release-v31
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/:S/release-v//}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/luaposix/luaposix/archive/release-v31.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luaposix/luaposix
COMMENT=	POSIX library (including curses) for lua
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:build
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGNAME_NOREV}

post-patch:
	${TOUCH} ${WRKSRC}/configure ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

post-install:
	cd ${DESTDIR}${PREFIX}/${LUA_CDIR} && \
	${LN} -fs ../../../share/${PKGNAME}/posix.lua && \
	${LN} -fs ../../../share/${PKGNAME}/curses.lua

.include "../../lang/lua/module.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
