# $NetBSD: Makefile,v 1.10 2000/11/08 17:47:14 itojun Exp $
#

DISTNAME=		jpilot-0.98.1
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.linuxave.net/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://jpilot.linuxave.net/

BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		gtk+>=1.2.0:../../x11/gtk
DEPENDS+=		pilot-link>=0.9.3:../../comms/pilot-link

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
USE_LIBINTL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}
# workaround gettext.m4 bug - may have bad sideeffect
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -lintl"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/jpilot/plugins

.include "../../mk/bsd.pkg.mk"
