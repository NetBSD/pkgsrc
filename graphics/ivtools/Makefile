# $NetBSD: Makefile,v 1.23 2010/04/05 22:52:23 markd Exp $

DISTNAME=	ivtools-1.2.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ivtools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ivtools.org/ivtools/
COMMENT=	Drawing editors for PostScript, TeX, and web graphics

CONFLICTS+=	dclock-[0-9]*

DEPENDS+=	pstoedit>=3.0:../../graphics/pstoedit
DEPENDS+=	wget>=1.0:../../net/wget

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	imake bash:run

REPLACE_BASH+=	src/scripts/ivgetjpg.bash src/scripts/ivtiftopnm.bash

WRKSRC=		${WRKDIR}/ivtools-1.2
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-tiff=${BUILDLINK_PREFIX.tiff}

post-patch:
	${RM} -f ${WRKSRC}/src/include/ivstd/strstream.h
	${TOUCH} ${WRKSRC}/config/dragonfly-gcc.mk

pre-install:
	${RM} -f ${WRKSRC}/config/local.def.orig
	${RM} -f ${WRKSRC}/config/params.def.orig
	${RM} -f ${WRKSRC}/config/rules.def.orig
	${RM} -f ${WRKSRC}/config/site.def.*.orig
	${RM} -f ${WRKSRC}/config/arch.def.orig

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
