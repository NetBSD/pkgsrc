# $NetBSD: Makefile,v 1.1 2013/10/30 06:18:10 dholland Exp $

DISTNAME=	lua-${LUA_VERSION}
PKGNAME=	lua52-${LUA_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		http://www.tecgraf.puc-rio.br/lua/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lua.org/
COMMENT=	Powerful light-weight language for extending applications
LICENSE=	mit

.include "../../lang/lua52/version.mk"

PKG_INSTALLATION_TYPES=	overwrite pkgviews
CONFLICTS+=	lua-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	DLLIB=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}
CFLAGS+=	-DLUA_ROOT=\"${PREFIX}/\"

PKGCONFIG_OVERRIDE=	${WRKSRC}/lua.pc
INSTALLATION_DIRS+=	lib/pkgconfig share/doc/lua

.if ${OPSYS} == "FreeBSD"
BUILD_TARGET=	freebsd
.elif !empty(OPSYS:M*BSD*) || ${OPSYS} == "DragonFly"
BUILD_TARGET=	bsd
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	linux
.elif ${OPSYS} == "Darwin"
BUILD_TARGET=	macosx
.elif ${OPSYS} == "SunOS"
BUILD_TARGET=	solaris
.elif ${OPSYS} == "AIX"
BUILD_TARGET=	aix
.else
BUILD_TARGET=	generic
.endif

pre-configure:
	sed	-e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@VER@,${PKGVERSION_NOREV:R},g' \
		-e 's,@REV@,${PKGVERSION_NOREV},g' \
		${FILESDIR}/lua.pc.in > ${WRKSRC}/lua.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/lua.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/doc/*.??? ${DESTDIR}${PREFIX}/share/doc/lua
	${INSTALL_DATA} ${WRKSRC}/doc/*.???? ${DESTDIR}${PREFIX}/share/doc/lua

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
