# $NetBSD: Makefile,v 1.6 1998/05/28 22:16:18 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp
#

DISTNAME=       xpaint-2.5
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes
CAT1=		xpaint.0

pre-configure:
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' \
		-e 's|\$${X11BASE}|'${X11BASE}'|g' \
		< ${WRKSRC}/Local.config > ${WRKSRC}/Local.config.new && \
	${MV} -f ${WRKSRC}/Local.config.new ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
