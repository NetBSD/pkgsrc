# $NetBSD: Makefile,v 1.37 2005/02/23 03:28:49 minskim Exp $
#

DISTNAME=		snd
PKGNAME=		snd-19980212
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ccrma-www.stanford.edu/CCRMA/Software/snd/snd.html
COMMENT=		X based sound editor

NO_SRC_ON_FTP=		Already on MASTER_SITE_LOCAL

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		YES
USE_X11=		YES

MAKEFILE=		makefile.netbsd
BUILD_TARGET=		snd

HTMLDIR=		${PREFIX}/share/doc/html/snd

INSTALLATION_DIRS=	bin lib/X11/app-defaults

do-install:
	cd ${WRKSRC} ; ${INSTALL_PROGRAM} snd ${PREFIX}/bin
	cd ${WRKSRC} ; ${INSTALL_DATA} Snd.ad ${PREFIX}/lib/X11/app-defaults/Snd
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} *.gif *.html *.txt README.Snd ${HTMLDIR}

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
