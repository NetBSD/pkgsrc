# $NetBSD: Makefile,v 1.16 2001/04/02 20:06:11 wiz Exp $
#

DISTNAME=		jpilot-0.99
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.org/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://jpilot.org/
COMMENT=		desktop organizer application for the palm pilot

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	yes
DEPENDS+=		gtk+>=1.2.0:../../x11/gtk
DEPENDS+=		pilot-link>=0.9.3:../../comms/pilot-link

CONFLICTS+=		jpilot-libplugin-*

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_X11=		# defined
USE_LIBINTL=		# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
EVAL_PREFIX+=		GTKDIR=gtk+
EVAL_PREFIX+=		PILOTLINKDIR=pilot-link
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${PILOTLINKDIR}"
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

INCDIR=			${PREFIX}/include/jpilot
HTMLDIR=		${PREFIX}/share/doc/html/jpilot
MAN1DIR=		${PREFIX}/man/man1
PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins

post-extract:
	${RM} -f ${WRKSRC}/po/Makefile.in

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${INCDIR} ${HTMLDIR} ${PLUGINSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} libplugin.h prefs.h ${INCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/docs; ${INSTALL_MAN} *.1 ${MAN1DIR}
	${TOUCH} ${PLUGINSDIR}/.directory

.include "../../mk/bsd.pkg.mk"
