# $NetBSD: Makefile,v 1.33 2002/10/21 12:26:29 wiz Exp $
#

DISTNAME=       xpaint-2.6.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}/xpaint
CATEGORIES=	graphics x11
MASTER_SITES=	http://home.worldonline.dk/~torsten/xpaint/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://home.worldonline.dk/~torsten/xpaint/
COMMENT=	Simple paint program

USE_BUILDLINK2=	YES
USE_IMAKE=      YES
USE_RMAN=	YES

PLIST_SRC=	${WRKDIR}/PLIST

pre-configure:
	${MV} -f ${WRKSRC}/Local.config ${WRKSRC}/Local.config.save
	@${SED} -e 's|\$${LOCALBASE}|${LOCALBASE}|g' \
		-e 's|\$${X11BASE}|${X11BASE}|g' \
		-e 's|\$${XPMDIR}|${BUILDLINK_PREFIX.xpm}|g' \
		${WRKSRC}/Local.config.save > ${WRKSRC}/Local.config

post-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	if [ -f  ${PREFIX}/lib/X11/doc/html/xpaint.1.html ]; then \
	  ${ECHO} lib/X11/doc/html/xpaint.1.html >>${PLIST_SRC}; \
	fi

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
