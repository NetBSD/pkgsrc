# $NetBSD: Makefile,v 1.8 1998/07/04 05:11:14 mycroft Exp $
# FreeBSD Id: Makefile,v 1.14 1997/08/29 12:17:50 tg Exp
#

DISTNAME=       xpaint-2.5
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.danbbs.dk/~torsten/xpaint/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png

WRKSRC=		${WRKDIR}/xpaint
USE_IMAKE=      yes

pre-configure:
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' \
		-e 's|\$${X11BASE}|'${X11BASE}'|g' \
		< ${WRKSRC}/Local.config > ${WRKSRC}/Local.config.new && \
	${MV} -f ${WRKSRC}/Local.config.new ${WRKSRC}/Local.config

.include "../../mk/bsd.pkg.mk"
