# $NetBSD: Makefile,v 1.35 2000/09/15 00:39:05 hubertf Exp $
#

ETHEREAL_VERSION=	0.8.12
DISTNAME=		ethereal-${ETHEREAL_VERSION}
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base

USE_X11=		yes
GNU_CONFIGURE=		yes
EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"

PLIST_SUBST+=		ETHEREAL_VERSION=${ETHEREAL_VERSION}

.include "../../mk/bsd.pkg.mk"
