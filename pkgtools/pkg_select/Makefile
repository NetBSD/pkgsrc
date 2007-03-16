# $NetBSD: Makefile,v 1.9 2007/03/16 20:22:16 rillig Exp $
#

DISTNAME=	pkg_select-20050817
PKGREVISION=	2
CATEGORIES=	pkgtools
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
COMMENT=	Curses based pkgsrc system browser / manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/pkg_select

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${EXAMPLEDIR} share/pkg_select

EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EXAMPLEDIR}/${PKGBASE}.conf.example	\
			${PKG_SYSCONFDIR}/${PKGBASE}.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile pkg_select.1 ${PKGBASE}.conf.example
SUBST_SED.path=		-e "s|/usr/pkgsrc|${PKGSRCDIR}|g"
SUBST_SED.path+=	-e "s|/usr/pkg/etc|${PKG_SYSCONFDIR}|g"
SUBST_SED.path+=	-e "s|/usr/pkg|${PREFIX}|g"
SUBST_SED.path+=	-e "s|/var/db/pkg|${PKG_DBDIR}|g"
SUBST_SED.path+=	-e "s|/usr/bin/make|${MAKE}|g"

CFLAGS+=		-DPKGTOOLS_PATH=\"${PKG_TOOLS_BIN}\"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_select ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.conf.example ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/mirrors.cvs ${PREFIX}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC}/mirrors.ftp ${PREFIX}/share/pkg_select
	${INSTALL_MAN} ${WRKSRC}/pkg_select.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
