# $NetBSD: Makefile,v 1.13 1998/12/20 15:09:30 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp
#

DISTNAME=       xpaint-2.5.6
WRKSRC=		${WRKDIR}/xpaint
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.danbbs.dk/~torsten/xpaint/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png

CONFLICTS=	xpaint-2.5

USE_IMAKE=      yes

pre-configure:
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' \
		-e 's|\$${X11BASE}|'${X11BASE}'|g' \
		< ${WRKSRC}/Local.config > ${WRKSRC}/Local.config.new && \
	${MV} -f ${WRKSRC}/Local.config.new ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
