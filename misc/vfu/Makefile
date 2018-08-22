# $NetBSD: Makefile,v 1.60 2018/08/22 09:45:47 wiz Exp $
#

DISTNAME=	vfu-3.04
PKGREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	http://cade.datamax.bg/vfu/
MASTER_SITES+=	${MASTER_SITE_SUNSITE:=utils/file/managers/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cade.datamax.bg/vfu/
COMMENT=	Small, handy, easy-to-use file manager

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run
REPLACE_PERL+=	rx/rx_*
FAKE_NCURSES=	yes

DOCDIR=		${PREFIX}/share/doc/vfu
EGDIR=		${PREFIX}/share/examples/vfu

CONF_FILES=	${EGDIR}/vfu.conf ${PKG_SYSCONFDIR}/vfu.conf

MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PREFIX=${DESTDIR}${PREFIX} ${SH} install

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} COPYING INSTALL CONFIG FAQ HISTORY NOTES README \
		README.DOS THANKS.TO TODO XWINDOW.NOTES ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} ${WRKSRC}/vfu.conf ${DESTDIR}${EGDIR}/vfu.conf

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
