# $NetBSD: Makefile,v 1.18 2003/03/29 12:41:17 jmmv Exp $
#

DISTNAME=	hp2xx-3.4.0
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}/sources
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

DEPENDS+=	png>=1.2.1:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff

USE_X11=	yes
INFO_FILES=	hp2xx.info

post-extract:
	${CP} ${WRKSRC}/../makes/generic.mak ${WRKSRC}/Makefile

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
