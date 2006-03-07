# $NetBSD: Makefile,v 1.21 2006/03/07 20:39:55 minskim Exp $

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

BROKEN_GETTEXT_DETECTION=	yes
PTHREAD_OPTS+=			require

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
