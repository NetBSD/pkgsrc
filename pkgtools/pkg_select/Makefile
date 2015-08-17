# $NetBSD: Makefile,v 1.21 2015/08/17 17:11:28 wiz Exp $
#

DISTNAME=	pkg_select-20090308
PKGREVISION=	4
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/imil/

MAINTAINER=	imil@gcu.info
COMMENT=	Curses based pkgsrc system browser / manager
LICENSE=	original-bsd

USE_FEATURES+=		cdefs

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${EXAMPLEDIR} share/pkg_select

EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EXAMPLEDIR}/${PKGBASE}.conf.example	\
			${PKG_SYSCONFDIR}/${PKGBASE}.conf

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Wno-traditional
.endif

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Adjusting path.
SUBST_FILES.path=	Makefile pkg_select.1 ${PKGBASE}.conf.example
SUBST_SED.path=		-e "s|/usr/pkgsrc|${PKGSRCDIR}|g"
SUBST_SED.path+=	-e "s|/usr/pkg/etc|${PKG_SYSCONFDIR}|g"
SUBST_SED.path+=	-e "s|/usr/pkg/|${PREFIX}/|g"
SUBST_SED.path+=	-e "s|/var/db/pkg|${PKG_DBDIR}|g"
SUBST_SED.path+=	-e "s|/usr/bin/make|${MAKE}|g"

CFLAGS+=		-DPKGTOOLS_PATH=\"${PKG_TOOLS_BIN}\"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkg_select ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.conf.example 		\
		${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/mirrors.cvs				\
		${DESTDIR}${PREFIX}/share/pkg_select
	${INSTALL_DATA} ${WRKSRC}/mirrors.ftp				\
		${DESTDIR}${PREFIX}/share/pkg_select
	${INSTALL_MAN} ${WRKSRC}/pkg_select.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
