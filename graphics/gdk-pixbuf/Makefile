# $NetBSD: Makefile,v 1.10 2000/11/29 17:24:53 wiz Exp $
#
.include "Makefile.common"

PKGNAME=	${DISTNAME}nb1

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
