# $NetBSD: Makefile,v 1.23 2004/01/20 12:18:16 agc Exp $
#

DISTNAME=	hp2xx-3.4.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

WRKSRC=		${WRKDIR}/${DISTNAME}/sources
USE_X11=	yes
USE_BUILDLINK2=	YES
USE_MAKEINFO=	YES
INFO_FILES=	hp2xx.info

post-extract:
	${CP} ${WRKSRC}/../makes/generic.mak ${WRKSRC}/Makefile

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
