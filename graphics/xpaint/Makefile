# $NetBSD: Makefile,v 1.24 2000/09/01 13:43:37 hubertf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp
#

DISTNAME=       xpaint-2.5.6
WRKSRC=		${WRKDIR}/xpaint
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.worldonline.dk/~torsten/xpaint/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://home.worldonline.dk/~torsten/xpaint/

DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_IMAKE=      YES
USE_XPM=	YES

EVAL_PREFIX=	XPMDIR=xpm

pre-configure:
	${MV} -f ${WRKSRC}/Local.config ${WRKSRC}/Local.config.save
	@${SED} -e 's|\$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|\$${X11BASE}|${X11BASE}|g' \
		-e 's|\$${XPMDIR}|${XPMDIR}|g' \
		${WRKSRC}/Local.config.save > ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
