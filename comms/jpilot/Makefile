# $NetBSD: Makefile,v 1.28 2002/09/10 16:06:34 wiz Exp $
#

DISTNAME=		jpilot-0.99
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		desktop organizer application for the palm pilot

BUILD_USES_MSGFMT=	# defined

CONFLICTS+=		jpilot-libplugin-[0-9]*

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_DIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

INCDIR=			${PREFIX}/include/jpilot
HTMLDIR=		${PREFIX}/share/doc/html/jpilot
MAN1DIR=		${PREFIX}/man/man1
PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins

post-extract:
	${RM} -f ${WRKSRC}/po/Makefile.in

pre-configure:
	${SED} "s|@PREFIX@|${PREFIX}|g" ${WRKSRC}/docs/jpilot.1 \
			> ${WRKSRC}/docs/jpilot.1.patched && \
		${MV} ${WRKSRC}/docs/jpilot.1.patched ${WRKSRC}/docs/jpilot.1

post-install:
	${INSTALL_DATA_DIR} ${INCDIR} ${HTMLDIR} ${PLUGINSDIR} \
		${PREFIX}/share/doc/jpilot
	cd ${WRKSRC}; ${INSTALL_DATA} libplugin.h prefs.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/jpilot
	cd ${WRKSRC}/docs; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/docs; ${INSTALL_MAN} *.1 ${MAN1DIR}
	${TOUCH} ${PLUGINSDIR}/.directory

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
