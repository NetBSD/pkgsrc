# $NetBSD: Makefile,v 1.9 2002/11/30 12:41:06 salo Exp $

DISTNAME=	gabber-0.8.7
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gabber/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gabber.sourceforge.net/
COMMENT=	Gnome Jabber Client

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-xmms --disable-sigctest

.include "../../devel/gal/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../devel/libsigc++/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../x11/gnome--/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
