# $NetBSD: Makefile,v 1.28 2005/04/11 21:46:04 tv Exp $
#

DISTNAME=	hp2xx-3.4.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

WRKSRC=		${WRKDIR}/${DISTNAME}/sources
USE_X11=	yes
USE_MAKEINFO=	YES
INFO_FILES=	hp2xx.info

post-extract:
	${CP} ${WRKSRC}/../makes/generic.mak ${WRKSRC}/Makefile

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
