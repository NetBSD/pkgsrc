# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:27 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp
#

DISTNAME=       xpaint-2.5
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=    jpeg.7.:${PORTSDIR}/graphics/jpeg \
		tiff.3.:${PORTSDIR}/graphics/tiff \
		Xpm.4.:${PORTSDIR}/graphics/xpm   \
		png.0.:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes
CAT1=		xpaint.0

pre-configure:
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' \
		-e 's|\$${X11BASE}|'${X11BASE}'|g' \
		< ${WRKSRC}/Local.config > ${WRKSRC}/Local.config.new && \
	${MV} ${WRKSRC}/Local.config.new ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
