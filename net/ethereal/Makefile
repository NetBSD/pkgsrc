# $NetBSD: Makefile,v 1.4 1999/06/04 11:52:04 tron Exp $
#

DISTNAME=		ethereal-0.6.2
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.2:../../x11/gtk

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
