# $NetBSD: Makefile,v 1.46 2012/10/06 14:10:50 asau Exp $
#

.include "Makefile.common"

PKGREVISION=	17
COMMENT=	The GNOME image loading library

# XXX hopefully there is no x.gnome-config.x in PATH
post-patch:
	${SED} -e 's/gnome-config/x.gnome-config.x/g' \
	  ${WRKSRC}/configure >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/configure
	${CHMOD} a+x ${WRKSRC}/configure

post-configure:
	${SED} -e 's/ doc$$//' ${WRKSRC}/Makefile >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/Makefile

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/gnomecanvaspixbufConf.sh

.include "../../mk/bsd.pkg.mk"
