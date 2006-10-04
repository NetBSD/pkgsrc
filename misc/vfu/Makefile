# $NetBSD: Makefile,v 1.45 2006/10/04 21:49:19 wiz Exp $
#

DISTNAME=	vfu-3.04
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://cade.datamax.bg/vfu/ \
		${MASTER_SITE_SUNSITE:=utils/file/managers/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cade.datamax.bg/vfu/
COMMENT=	Small, handy, easy-to-use file manager

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run
REPLACE_PERL+=	rx/rx_*

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-U]-*

DOCDIR=		${PREFIX}/share/doc/vfu
EGDIR=		${PREFIX}/share/examples/vfu

CONF_FILES=	${EGDIR}/vfu.conf ${PKG_SYSCONFDIR}/vfu.conf

MAKE_ENV+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build.netbsd

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} COPYING INSTALL CONFIG FAQ HISTORY NOTES README \
		README.DOS THANKS.TO TODO XWINDOW.NOTES ${DOCDIR}
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} ${WRKSRC}/vfu.conf ${EGDIR}/vfu.conf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
