# $NetBSD: Makefile,v 1.2 2002/07/16 11:56:45 agc Exp $

DISTNAME=	gabber-0.8.7
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gabber/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gabber.sourceforge.net/
COMMENT=	Gnome Jabber Client

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-xmms

.include "../../textproc/scrollkeeper/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/libsigc++/buildlink.mk"
.include "../../x11/gtk--/buildlink.mk"
.include "../../x11/gnome--/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
