# $NetBSD: Makefile,v 1.10 2005/03/01 20:49:47 markd Exp $

DISTNAME=	ivtools-1.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.ivtools.org/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-*

WRKSRC=		${WRKDIR}/${PKGNAME:C/\.[0-9]$//}
GNU_CONFIGURE=	YES
USE_X11=	YES

post-patch:
	${RM} -f ${WRKSRC}/src/include/ivstd/strstream.h

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig
	${RM} -f ${WRKSRC}/config/site.def.NETBSD.orig

.include "../../mk/bsd.pkg.mk"
