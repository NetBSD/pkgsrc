# $NetBSD: Makefile,v 1.30 2000/08/03 23:12:11 frueauf Exp $
#

DISTNAME=		ethereal-0.8.11
CATEGORIES=		net
MASTER_SITES=		http://ethereal.zing.org/distribution/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://ethereal.zing.org/

DEPENDS=		gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=		${LOCALBASE}/bin/perl:../../lang/perl5

USE_X11=		yes
GNU_CONFIGURE=		yes

EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"

.include "../../mk/bsd.pkg.mk"
