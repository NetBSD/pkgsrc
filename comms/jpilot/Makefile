# $NetBSD: Makefile,v 1.8 2000/11/08 13:11:16 tron Exp $
#

DISTNAME=		jpilot-0.98.1
CATEGORIES=		comms
MASTER_SITES=		http://jpilot.linuxave.net/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://jpilot.linuxave.net/

DEPENDS+=		gtk+>=1.2.0:../../x11/gtk
DEPENDS+=		pilot-link>=0.9.3:../../comms/pilot-link

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/jpilot/plugins

.include "../../mk/bsd.pkg.mk"
