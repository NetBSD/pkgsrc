# $NetBSD: Makefile,v 1.42 2004/10/03 00:13:16 tv Exp $
#

DISTNAME=		jpilot-0.99.5
PKGREVISION=		5
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		Desktop organizer application for the palm pilot

BUILD_USES_MSGFMT=	YES

CONFLICTS+=		jpilot-libplugin-[0-9]*

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.0
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_PREFIX.pilot-link-libs}"
CONFIGURE_ARGS+=	--enable-gtk2
LDFLAGS+=		-export-dynamic

DOCDIR=			${PREFIX}/share/doc/jpilot
INCDIR=			${PREFIX}/include/jpilot
HTMLDIR=		${PREFIX}/share/doc/html/jpilot
MAN1DIR=		${PREFIX}/man/man1
PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins

post-extract:
	${RM} -f ${WRKSRC}/po/Makefile.in

pre-configure:
	for file in ${WRKSRC}/docs/jpilot.1; do				\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${INCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${PLUGINSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} libplugin.h prefs.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/docs; ${INSTALL_MAN} *.1 ${MAN1DIR}
	${TOUCH} ${PLUGINSDIR}/.directory

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
