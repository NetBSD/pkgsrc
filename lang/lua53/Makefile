# $NetBSD: Makefile,v 1.1.1.1 2015/01/17 17:50:23 alnsn Exp $

DISTNAME=	lua-${LUA_VERSION}
PKGNAME=	lua53-${LUA_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		http://www.tecgraf.puc-rio.br/lua/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lua.org/
COMMENT=	Powerful light-weight language for extending applications
LICENSE=	mit

.include "../../lang/lua53/version.mk"

CONFLICTS+=	lua-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
MAKE_ENV+=	DLLIB=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}
CFLAGS+=	-DLUA_ROOT=\"${PREFIX}/\"

PKGCONFIG_OVERRIDE=	${WRKSRC}/lua.pc
INSTALLATION_DIRS+=	lib/pkgconfig share/doc/lua-5.3

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

DOCDIR=		${PREFIX}/share/doc/lua-5.3

pre-configure:
	sed	-e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@VER@,${PKGVERSION_NOREV:R},g' \
		-e 's,@REV@,${PKGVERSION_NOREV},g' \
		${FILESDIR}/lua.pc.in > ${WRKSRC}/lua.pc
	cp ${WRKSRC}/doc/lua.1  ${WRKSRC}/doc/lua5.3.1
	cp ${WRKSRC}/doc/luac.1 ${WRKSRC}/doc/luac5.3.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.[a-z][a-z][a-z] \
	    ${WRKSRC}/doc/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/lua.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/lua-5.3.pc

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
