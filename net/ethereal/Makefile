# $NetBSD: Makefile,v 1.5 1999/08/05 17:45:57 hubertf Exp $
#

DISTNAME=		ethereal-0.7.1
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.2:../../x11/gtk
BUILD_DEPENDS+=		perl-5.00404:${PKGSRCDIR}/lang/perl5

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
