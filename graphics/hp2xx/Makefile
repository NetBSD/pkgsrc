# $NetBSD: Makefile,v 1.8 2000/08/31 12:37:01 dmcmahill Exp $
#

DISTNAME=	hp2xx-3.3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html

DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11=	yes
INFO_FILES=	hp2xx.info

WRKSRC=		${WRKDIR}/${DISTNAME}/sources

post-extract:
	${CP} ${WRKSRC}/../makes/generic.mak ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
