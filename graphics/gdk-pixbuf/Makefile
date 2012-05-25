# $NetBSD: Makefile,v 1.45 2012/05/25 08:29:36 he Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

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
