# $NetBSD: Makefile,v 1.8 2020/03/26 12:18:17 nia Exp $

DISTNAME=	dhex_0.69
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	editors
MASTER_SITES=	https://dettus.net/dhex/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	https://www.dettus.net/dhex/
COMMENT=	Curses-based hex-editor with diff mode
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
FAKE_NCURSES=	yes

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.curses:Q}

MAN1=		dhex.1
MAN5=		dhexrc.5 dhex_markers.5 dhex_searchlog.5

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhex ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
