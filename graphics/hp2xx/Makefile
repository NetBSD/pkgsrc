# $NetBSD: Makefile,v 1.15 2001/09/27 23:18:12 jlam Exp $
#

DISTNAME=	hp2xx-3.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff

USE_X11=	yes
INFO_FILES=	hp2xx.info

WRKSRC=		${WRKDIR}/${DISTNAME}/sources

post-extract:
	${CP} ${WRKSRC}/../makes/generic.mak ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
