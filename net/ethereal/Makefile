# $NetBSD: Makefile,v 1.1.1.1 1998/11/23 15:05:21 hubertf Exp $
#

DISTNAME=		ethereal-0.5.0
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.0.6:../../x11/gtk10

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
