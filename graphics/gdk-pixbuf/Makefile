# $NetBSD: Makefile,v 1.29 2004/10/03 00:14:50 tv Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME}
PKGREVISION=	3
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
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gdk-pixbuf.m4 \
		${LOCALBASE}/share/aclocal/gdk-pixbuf.m4
	${RM} ${PREFIX}/lib/gnomecanvaspixbufConf.sh

.include "../../mk/bsd.pkg.mk"
