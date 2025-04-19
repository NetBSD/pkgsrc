# $NetBSD: Makefile,v 1.20 2025/04/19 07:58:16 wiz Exp $

DISTNAME=	newsraft-0.29
PKGREVISION=	3
CATEGORIES=	news
MASTER_SITES=	https://codeberg.org/newsraft/newsraft/archive/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://codeberg.org/newsraft
COMMENT=	Terminal based feed reader
LICENSE=	isc

WRKSRC=	${WRKDIR}/newsraft

USE_TOOLS+=	pkg-config pax
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

MAKE_FILE=	makefile

MAKE_FLAGS+=	CURSES_CFLAGS=-I${BUILDLINK_PREFIX.curses:Q}/include
MAKE_FLAGS+=	CURSES_LIBS=${BUILDLINK_LDADD.curses:Q}

EGDIR=			${PREFIX}/share/examples/newsraft

INSTALLATION_DIRS+=	bin man/man1 share/examples/newsraft

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newsraft ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} ${WRKSRC}/doc/newsraft.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	cd ${WRKSRC}/doc/examples && ${PAX} -wr . ${DESTDIR}${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
