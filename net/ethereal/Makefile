# $NetBSD: Makefile,v 1.3 1999/04/26 19:15:37 garbled Exp $
#

DISTNAME=		ethereal-0.5.1
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk10-1.0.6:../../x11/gtk10

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV+=		GTK_CONFIG="${X11BASE}/bin/gtk10-config"

.include "../../mk/bsd.pkg.mk"
