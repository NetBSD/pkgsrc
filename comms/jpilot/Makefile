# $NetBSD: Makefile,v 1.64 2009/05/20 00:58:08 wiz Exp $
#

DISTNAME=		jpilot-1.6.0
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://www.jpilot.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.jpilot.org/
COMMENT=		Desktop organizer application for the palm pilot

CONFLICTS+=		jpilot-libplugin-[0-9]*

USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_OLD_DES_API=	YES
USE_DIRS+=		xdg-1.4
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES+=		c

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk-prefix="${BUILDLINK_PREFIX.gtk2}"
CONFIGURE_ARGS+=	--with-pilot-prefix="${BUILDLINK_PREFIX.pilot-link-libs}"
LDFLAGS+=		-export-dynamic

DOCDIR=			${PREFIX}/share/doc/jpilot
INCDIR=			${PREFIX}/include/jpilot
MAN1DIR=		${PREFIX}/${PKGMANDIR}/man1
PLUGINSDIR=		${PREFIX}/lib/jpilot/plugins

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-extract:
	${RM} -f ${WRKSRC}/po/Makefile.in

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${INCDIR}
	${INSTALL_DATA_DIR} ${PLUGINSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} libplugin.h prefs.h ${INCDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DOCDIR}
	cd ${WRKSRC}/docs; ${INSTALL_MAN} *.1 ${MAN1DIR}
	${TOUCH} ${PLUGINSDIR}/.directory

.include "../../mk/bsd.pkg.mk"
