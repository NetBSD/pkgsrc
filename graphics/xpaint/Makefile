# $NetBSD: Makefile,v 1.35 2003/03/02 19:47:27 jschauma Exp $

DISTNAME=       xpaint-2.6.7
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program

USE_BUILDLINK2=	YES
USE_IMAKE=      YES
USE_RMAN=	YES
USE_X11BASE=	YES

ALL_TARGET=	xaw95static
MAKE_ENV+=	XMKMF="${XMKMF}"

pre-configure:
	${MV} -f ${WRKSRC}/Local.config ${WRKSRC}/Local.config.save
	${SED} -e 's|\$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|\$${X11BASE}|${X11BASE}|g' \
		-e 's|\$${XPMDIR}|${BUILDLINK_PREFIX.xpm}|g' \
		${WRKSRC}/Local.config.save > ${WRKSRC}/Local.config

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
