# $NetBSD: Makefile,v 1.7 2005/05/07 23:04:17 dillo Exp $
#

DISTNAME=	hugov31_unix_source
PKGNAME=	wxhugo-3.1.02
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/hugo/source/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTFILE_WX}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.generalcoffee.com/hugo.html
COMMENT=	Interactive fiction interpreter with sound and graphics support

DISTFILE_WX=	hugov31_wxwin_source${EXTRACT_SUFX}
#EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DIST_SUBDIR=	hugo-3.1.02
USE_GNU_TOOLS+=	make
WRKSRC=		${WRKDIR}/hugov3.1.02/hewx

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hewx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
