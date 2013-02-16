# $NetBSD: Makefile,v 1.48 2013/02/16 11:18:06 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	19
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
