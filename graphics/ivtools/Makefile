# $NetBSD: Makefile,v 1.4 2003/07/17 21:41:20 grant Exp $

DISTNAME=	ivtools-1.0.7
WRKSRC=		${WRKDIR}/${DISTNAME:C/\.[0-9]$//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.vectaport.com/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig

.include "../../mk/bsd.pkg.mk"
