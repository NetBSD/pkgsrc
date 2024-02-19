# $NetBSD: Makefile,v 1.1 2024/02/19 01:38:56 gdt Exp $

DISTNAME=	newsraft-0.22
CATEGORIES=	news
MASTER_SITES=	https://codeberg.org/newsraft/newsraft/archive/

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://codeberg.org/newsraft
COMMENT=	Terminal based feed reader
LICENSE=	isc

WRKSRC=	${WRKDIR}/newsraft

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config pax
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

MAKE_FILE=	makefile

EGDIR=			${PREFIX}/share/examples/newsraft

INSTALLATION_DIRS+=	bin man/man1 share/examples/newsraft

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newsraft ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} ${WRKSRC}/doc/newsraft.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	cd ${WRKSRC}/doc/examples && ${PAX} -wr . ${DESTDIR}${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
