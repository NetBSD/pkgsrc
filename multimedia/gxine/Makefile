# $NetBSD: Makefile,v 1.20 2006/03/04 21:30:14 jlam Exp $

DISTNAME=	gxine-0.4.9
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xinehq.de/
COMMENT=	Gtk-based media player

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PTHREAD_OPTS+=		require

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
