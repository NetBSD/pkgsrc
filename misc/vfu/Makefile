# $NetBSD: Makefile,v 1.65 2026/11/14 21:17:46 drixter Exp $

DISTNAME=	vfu-5.09
CATEGORIES=	misc
MASTER_SITES=	https://cade.noxrun.com/projects/vfu/

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://cade.noxrun.com/projects/vfu/
COMMENT=	Small, handy, easy-to-use file manager for UNIX/Linux
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config perl:run
REPLACE_PERL+=	rx/rx_*
USE_LANGUAGES=	c c++

USE_CURSES=	wide

MAKE_FLAGS+=	YASCREEN_CC=
MAKE_FLAGS+=	YASCREEN_LD=
MAKE_FLAGS+=	NO_FLTO=1
MAKE_FLAGS+=	NCURSES_CC=
MAKE_FLAGS+=	NCURSES_LD=${BUILDLINK_LDADD.curses}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/vfu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vfu/vfu \
		${DESTDIR}${PREFIX}/bin/vfu

	${INSTALL_SCRIPT} ${WRKSRC}/rx/rx_* \
		${DESTDIR}${PREFIX}/bin/

	${INSTALL_MAN} ${WRKSRC}/vfu.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vfu.1

	${INSTALL_DATA} ${WRKSRC}/vfu.conf \
		${DESTDIR}${PREFIX}/share/examples/vfu/vfu.conf


.include "../../devel/pcre2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
