# $NetBSD: Makefile,v 1.25 2014/05/15 14:41:58 adam Exp $
#

DISTNAME=	dikt-2j
PKGREVISION=	12
CATEGORIES=	textproc x11
MASTER_SITES=	http://dikt.googlecode.com/files/
EXTRACT_SUFX=	.txz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://dikt.googlecode.com/
COMMENT=	Dictionary protocol client for KDE
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4
BUILD_DEPENDS+=	xz-[0-9]*:../../archivers/xz

USE_TOOLS+=	tar
USE_LIBTOOL=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

do-extract:
	set -e; ${MKDIR} ${WRKDIR}; cd ${WRKDIR}; \
	${PREFIX}/bin/xz -dc ${DISTDIR}/${DISTNAME}.txz | tar -xf-

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
