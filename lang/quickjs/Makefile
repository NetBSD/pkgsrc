# $NetBSD: Makefile,v 1.22 2026/08/13 18:11:24 wiz Exp $

NAME=		quickjs
QJS_DATE=	2026-06-04
VERSION=	${QJS_DATE:S/-//g}
DISTNAME=	${NAME}-${QJS_DATE}
PKGNAME=	${NAME}-${VERSION}
PKGREVISION=	1
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

CFLAGS+=	-fPIC

# Requires C11 atomics support
USE_CC_FEATURES=	c11

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
HAS_ATOMIC_64!=	${CC} -E files/netbsd-has-atomic64.c | tail -1
.  if ${HAS_ATOMIC_64} == "YES"
MAKE_ENV+=	CONFIG_BIGNUM=yes
.  endif
.else # Not NetBSD && not Linux
# Presumed to be supported
MAKE_ENV+=	CONFIG_BIGNUM=yes
.endif

# Populate missing examples/message.json based on the file present in Git
# repository that is missing in the distfile. Without it the build fails with:
#
#  ReferenceError: could not load module filename 'examples/message.json'
#
pre-configure:
	${ECHO} '{ "x" : 1, "tab": [ 1, 2, 3 ] }' > ${WRKSRC}/examples/message.json

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.texi ${DESTDIR}${PREFIX}/share/doc/quickjs/
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.js *.c *.json ${DESTDIR}${PREFIX}/share/doc/quickjs/examples/
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.js *.c ${DESTDIR}${PREFIX}/share/doc/quickjs/tests/

.include "../../mk/bsd.pkg.mk"
