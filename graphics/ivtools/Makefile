# $NetBSD: Makefile,v 1.5 2003/11/18 21:09:18 markd Exp $

DISTNAME=	ivtools-1.1
PKGNAME=	ivtools-1.1.0
WRKSRC=		${WRKDIR}/${PKGNAME:C/\.[0-9]$//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.ivtools.org/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-*

GNU_CONFIGURE=	YES
USE_X11=	YES

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig
	${RM} -f ${WRKSRC}/config/site.def.NETBSD.orig

.include "../../mk/bsd.pkg.mk"
