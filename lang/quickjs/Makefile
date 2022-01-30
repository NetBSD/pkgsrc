# $NetBSD: Makefile,v 1.9 2022/01/30 10:55:03 he Exp $

NAME=		quickjs
QJS_DATE=	2021-03-27
VERSION=	${QJS_DATE:S/-//g}
DISTNAME=	${NAME}-${QJS_DATE}
PKGNAME=	${NAME}-${VERSION}
CATEGORIES=	lang
MASTER_SITES=	https://bellard.org/quickjs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bellard.org/quickjs/
COMMENT=	Quick JavaScript interpreter
LICENSE=	mit

USE_TOOLS+=	gmake
MAKE_FLAGS=	prefix=${PREFIX}
TEST_TARGET=	test
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	lto

.if ${OPSYS} == "NetBSD"
HAS_ATOMIC_64!=	${CC} -E files/netbsd-has-atomic64.c | tail -1
.  if (${HAS_ATOMIC_64} == "YES")
MAKE_ENV+=	CONFIG_BIGNUM=yes
.  endif
.elif ${OPSYS} == "Darwin" || ${OPSYS} == "Linux"
PLIST.lto=	yes
.else # Not NetBSD && not Linux
# Presumed to be supported
MAKE_ENV+=	CONFIG_BIGNUM=yes
.endif

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.pdf ${DESTDIR}${PREFIX}/share/doc/quickjs/
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.js *.c ${DESTDIR}${PREFIX}/share/doc/quickjs/examples/
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.js *.c ${DESTDIR}${PREFIX}/share/doc/quickjs/tests/

.include "../../mk/bsd.pkg.mk"
