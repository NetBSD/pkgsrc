# $NetBSD: Makefile,v 1.62 2022/06/28 11:36:09 wiz Exp $

DISTNAME=	dikt-2j
PKGREVISION=	46
CATEGORIES=	textproc x11
#MASTER_SITES=	http://dikt.googlecode.com/files/
EXTRACT_SUFX=	.txz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.dikt.tv/
COMMENT=	Dictionary protocol client for KDE
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4
BUILD_DEPENDS+=	xz-[0-9]*:../../archivers/xz

USE_TOOLS+=	tar
TOOLS_BROKEN+=	perl
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
