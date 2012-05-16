# $NetBSD: Makefile,v 1.27 2012/05/16 15:16:09 marino Exp $
#

DISTNAME=	ketm-0.0.6
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://home.t-online.de/home/haslbeck/ketm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.t-online.de/home/haslbeck/ketm/
COMMENT=	Old-school 2d-scrolling shooter

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	ketm

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/ketm/data

LDFLAGS.DragonFly=	-lm

SUBST_CLASSES+=		ketm
SUBST_STAGE.ketm=	pre-configure
SUBST_FILES.ketm=	*.c font.h
SUBST_SED.ketm=		-e "s,data/,${PREFIX}/share/ketm/data/,g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ketm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/ketm
	cd ${WRKSRC}/data && 						\
		${INSTALL_DATA} *.bmp *.dat ${DESTDIR}${PREFIX}/share/ketm/data

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
