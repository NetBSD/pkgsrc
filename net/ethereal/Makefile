# $NetBSD: Makefile,v 1.21 2000/04/18 09:03:47 frueauf Exp $
#

DISTNAME=		ethereal-0.8.7
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=		${LOCALBASE}/bin/perl:../../lang/perl5

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
