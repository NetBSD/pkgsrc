# $NetBSD: Makefile,v 1.3 2000/05/05 13:43:07 hubertf Exp $
#

DISTNAME=		gtk-gnutella-0.12
CATEGORIES=		net
MASTER_SITES=		http://gtk-gnutella.sourceforge.net/download/ \
			ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/

DEPENDS=		gtk+-1.2.*:../../x11/gtk

USE_GMAKE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}

.include "../../mk/bsd.pkg.mk"
