# $NetBSD: Makefile,v 1.29 2001/05/22 09:32:23 wiz Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp

DISTNAME=       xpaint-2.6.1
WRKSRC=		${WRKDIR}/xpaint
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.worldonline.dk/~torsten/xpaint/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://home.worldonline.dk/~torsten/xpaint/
COMMENT=	Simple paint program

DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

USE_IMAKE=      YES
USE_XPM=	YES
USE_RMAN=	YES

EVAL_PREFIX=	XPMDIR=xpm
PLIST_SRC=	${WRKDIR}/PLIST

pre-configure:
	${MV} -f ${WRKSRC}/Local.config ${WRKSRC}/Local.config.save
	@${SED} -e 's|\$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|\$${X11BASE}|${X11BASE}|g' \
		-e 's|\$${XPMDIR}|${XPMDIR}|g' \
		${WRKSRC}/Local.config.save > ${WRKSRC}/Local.config

post-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	if [ -f  ${PREFIX}/lib/X11/doc/html/xpaint.1.html ]; then \
	  ${ECHO} lib/X11/doc/html/xpaint.1.html >>${PLIST_SRC}; \
	fi

.include "../../mk/bsd.pkg.mk"
