# $NetBSD: Makefile,v 1.14 2005/12/16 07:09:24 wiz Exp $

DISTNAME=	ivtools-1.2.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.ivtools.org/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-[0-9]*

DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit
DEPENDS+=	wget>=1.0:../../net/wget

WRKSRC=		${WRKDIR}/ivtools-1.2
GNU_CONFIGURE=	YES

.include "../../mk/x11.buildlink3.mk"

post-patch:
	${RM} -f ${WRKSRC}/src/include/ivstd/strstream.h

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig
	${RM} -f ${WRKSRC}/config/site.def.NETBSD.orig

.include "../../mk/bsd.pkg.mk"
