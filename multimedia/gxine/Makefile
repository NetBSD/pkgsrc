# $NetBSD: Makefile,v 1.27 2006/10/17 16:23:47 drochner Exp $

DISTNAME=	gxine-0.5.8
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xinehq.de/
COMMENT=	Gtk-based media player

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

BROKEN_GETTEXT_DETECTION=	yes
PTHREAD_OPTS+=			require

EGDIR=			${PREFIX}/share/examples/gxine
PKG_SYSCONFSUBDIR=	gxine

.for f in gtkrc keypad.xml startup toolbar-fullscreen.xml toolbar-window.xml
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/firefox/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
