# $NetBSD: Makefile,v 1.7 2001/06/16 19:53:09 jlam Exp $

.include "../gdk-pixbuf/Makefile.common"

PKGNAME=	${DISTNAME:S/gdk-pixbuf-/gdk-pixbuf-gnome-/}

COMMENT=	the GNOME image loading library GNOME canvas support add-on

CONFLICTS+=	gdk-pixbuf<0.10.1

GDK_PIXBUF_REQD=	0.10.1

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	for file in gnomecanvaspixbufConf.sh; do			\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdk-pixbuf/gnome-canvas-pixbuf.h \
	  ${PREFIX}/include/gdk-pixbuf
	${INSTALL_DATA} ${WRKSRC}/gnomecanvaspixbufConf.sh \
	  ${PREFIX}/lib
	cd ${WRKSRC}/gdk-pixbuf && \
	${SH} ../libtool --mode=install ${INSTALL_DATA} \
	  libgnomecanvaspixbuf.la ${PREFIX}/lib
	cd ${WRKSRC}/doc && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	  ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
