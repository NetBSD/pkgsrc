# $NetBSD: Makefile,v 1.1.1.1 2000/06/15 09:14:23 rh Exp $
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
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
