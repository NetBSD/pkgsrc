# $NetBSD: Makefile,v 1.11 2001/02/16 15:22:20 wiz Exp $
#
.include "Makefile.common"

PKGNAME=	${DISTNAME}nb1

COMMENT=	the GNOME image loading library

post-patch:
	${SED} "s/BUILD_CANVAS=yes/BUILD_CANVAS=no/g" \
		${WRKSRC}/configure.in > ${WRKSRC}/.tmp \
	&& ${MV} ${WRKSRC}/.tmp ${WRKSRC}/configure.in

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gdk-pixbuf.m4 \
		${LOCALBASE}/share/aclocal/gdk-pixbuf.m4
	${RM} ${PREFIX}/lib/gnomecanvaspixbufConf.sh

.include "../../mk/bsd.pkg.mk"
