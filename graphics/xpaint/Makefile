# $NetBSD: Makefile,v 1.31 2002/02/05 22:08:26 drochner Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp

DISTNAME=       xpaint-2.6.2
WRKSRC=		${WRKDIR}/xpaint
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.worldonline.dk/~torsten/xpaint/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://home.worldonline.dk/~torsten/xpaint/
COMMENT=	Simple paint program

DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
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
