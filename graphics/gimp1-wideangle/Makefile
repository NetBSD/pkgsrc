# $NetBSD: Makefile,v 1.15 2010/02/03 23:11:15 joerg Exp $
#

DISTNAME=	wideangleFeb03
PKGNAME=	gimp-wideangle-0.4
PKGREVISION=			7
CATEGORIES=	graphics
MASTER_SITES=	http://members.ozemail.com.au/~hodsond/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://members.ozemail.com.au/~hodsond/
COMMENT=	GIMP plugin for wideangle lens distortions

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wideangle
USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=		wideangle
INSTALLATION_DIRS+=	lib/gimp/1.2/plug-ins

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wideangle ${DESTDIR}${PREFIX}/lib/gimp/1.2/plug-ins

.include "../../graphics/gimp1-base/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
