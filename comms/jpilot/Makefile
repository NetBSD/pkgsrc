# $NetBSD: Makefile,v 1.4 2000/07/10 10:40:39 agc Exp $
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
CONFIGURE_ARGS+=	--with-gtk-prefix="`${PKG_INFO} -qp gtk+ | ${AWK} '{print $$2}'`"
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/jpilot/plugins

.include "../../mk/bsd.pkg.mk"
