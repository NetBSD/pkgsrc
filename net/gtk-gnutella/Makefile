# $NetBSD: Makefile,v 1.9 2001/02/17 18:18:56 wiz Exp $
#

DISTNAME=		gtk-gnutella-0.12
CATEGORIES=		net
MASTER_SITES=		http://gtk-gnutella.sourceforge.net/download/ \
			ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gtk-gnutella.sourceforge.net/
COMMENT=		GTk-based gnutella client

DEPENDS=		gtk+-1.2.*:../../x11/gtk

USE_GMAKE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

EVAL_PREFIX+=		GTKDIR=gtk+
CONFIGURE_ARGS+=	--with-gtk-prefix="${GTKDIR}"

.include "../../mk/bsd.pkg.mk"
