# $NetBSD: Makefile,v 1.2 1999/02/19 14:32:49 rh Exp $
#

DISTNAME=		ethereal-0.5.1
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk10-1.0.6:../../x11/gtk10

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV+=		GTK_CONFIG="${X11BASE}/bin/gtk10-config"

.include "../../mk/bsd.pkg.mk"
