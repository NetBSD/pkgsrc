# $NetBSD: Makefile,v 1.17 2001/08/29 22:41:17 jlam Exp $
#

PKGNAME=	${DISTNAME}
COMMENT=	the GNOME image loading library

REPLACE_BUILDLINK=	gdk_pixbufConf.sh
REPLACE_BUILDLINK+=	gdk_pixbuf_xlibConf.sh

.include "Makefile.common"

post-patch:
	${SED} -e 's/BUILD_CANVAS=yes/BUILD_CANVAS=no/g' \
	  ${WRKSRC}/configure.in >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/configure.in

post-configure:
	${SED} -e 's/ doc$$//' ${WRKSRC}/Makefile >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/Makefile

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gdk-pixbuf.m4 \
		${LOCALBASE}/share/aclocal/gdk-pixbuf.m4
	${RM} ${PREFIX}/lib/gnomecanvaspixbufConf.sh

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
