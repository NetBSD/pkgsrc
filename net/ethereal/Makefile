# $NetBSD: Makefile,v 1.10 1999/09/04 20:47:37 tron Exp $
#

DISTNAME=		ethereal-0.7.3
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.4:../../x11/gtk
BUILD_DEPENDS+=		${LOCALBASE}/bin/perl:../../lang/perl5

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
