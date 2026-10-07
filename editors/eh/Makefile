# $NetBSD: Makefile,v 1.1 2026/10/07 00:14:48 agc Exp $

DISTNAME=		eh-${VERSION}
VERSION=		1.9.0
CATEGORIES=		editors
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=SirWumpus/eh/archive/v${VERSION}.tar.gz}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://codeberg.org/SirWumpus/eh
COMMENT=		Minimalist version of the vi editor
LICENSE=		2-clause-bsd

WRKSRC=			${WRKDIR}/eh

USE_LANGUAGES=		c

USE_BSD_MAKEFILE=	yes
AUTO_MKDIRS=		yes
TEST_TARGET=		t

_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
DATE_CMD=		date -u +'%a, %d %b %Y %H:%M:%SZ'
BUILT=			${DATE_CMD:sh}
CPPFLAGS+=		-DBUILT="\"${BUILT}\"" -DVERSION="\"${VERSION}\""

do-build:
	(cd ${WRKSRC} && ${CC} ${CPPFLAGS} eh.c -o eh -lcurses)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eh ${DESTDIR}${PREFIX}/bin

.include "../../mk/curses.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
