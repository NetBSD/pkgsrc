# $NetBSD: Makefile,v 1.20.2.3 2002/06/23 18:46:21 jlam Exp $
#

PKGNAME=	${DISTNAME}
COMMENT=	the GNOME image loading library

USE_BUILDLINK2=	# defined

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

.include "../../mk/bsd.pkg.mk"
