# $NetBSD: Makefile,v 1.2 2010/11/17 14:35:32 drochner Exp $
#

DISTNAME=	dconf-0.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/dconf
COMMENT=	Backend for gsettings
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-editor
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in

.include "../../devel/glib2/modules.mk"
.include "../../mk/bsd.pkg.mk"
