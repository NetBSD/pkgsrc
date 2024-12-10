# $NetBSD: Makefile,v 1.2 2024/12/10 20:32:45 wiz Exp $

DISTNAME=	mtm-1.2.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=deadpixi/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/deadpixi/mtm/
COMMENT=	The Micro Terminal Multiplexer
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/mtm/terminfo

LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib
LDFLAGS+=	-L${BUILDLINK_PREFIX.ncurses}/lib

USE_CURSES+=	wgetscrreg
FAKE_NCURSES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtm ${DESTDIR}/${PREFIX}/bin && \
	${INSTALL_MAN} ${WRKSRC}/mtm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${DESTDIR}${PREFIX}/share/mtm/terminfo

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
