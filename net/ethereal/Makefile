# $NetBSD: Makefile,v 1.28 2000/07/14 16:04:24 agc Exp $
#

DISTNAME=		ethereal-0.8.10
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=		${LOCALBASE}/bin/perl:../../lang/perl5

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix="`${SHOW_PREFIX1} gtk+ ${SHOW_PREFIX2}`"

.include "../../mk/bsd.pkg.mk"
