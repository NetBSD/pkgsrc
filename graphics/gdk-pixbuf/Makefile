# $NetBSD: Makefile,v 1.14 2001/06/16 19:53:08 jlam Exp $
#
.include "Makefile.common"

PKGNAME=	${DISTNAME}

COMMENT=	the GNOME image loading library

post-patch:
	${SED} -e 's/BUILD_CANVAS=yes/BUILD_CANVAS=no/g' \
	  ${WRKSRC}/configure.in >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/configure.in

post-configure:
	${SED} -e 's/ doc$$//' ${WRKSRC}/Makefile >${WRKSRC}/.tmp && \
	${MV} ${WRKSRC}/.tmp ${WRKSRC}/Makefile

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	for file in gdk_pixbufConf.sh gdk_pixbuf_xlibConf.sh; do	\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

post-install:
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/gdk-pixbuf.m4 \
		${LOCALBASE}/share/aclocal/gdk-pixbuf.m4
	${RM} ${PREFIX}/lib/gnomecanvaspixbufConf.sh

.include "../../mk/bsd.pkg.mk"
