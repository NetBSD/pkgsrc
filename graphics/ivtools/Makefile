# $NetBSD: Makefile,v 1.11 2005/06/01 18:02:56 jlam Exp $

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

.include "../../mk/x11.buildlink3.mk"

post-patch:
	${RM} -f ${WRKSRC}/src/include/ivstd/strstream.h

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig
	${RM} -f ${WRKSRC}/config/site.def.NETBSD.orig

.include "../../mk/bsd.pkg.mk"
