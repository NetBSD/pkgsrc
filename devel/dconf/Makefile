# $NetBSD: Makefile,v 1.8 2012/03/03 00:12:00 wiz Exp $
#

DISTNAME=	dconf-0.5.1
PKGREVISION=	3
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
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in

BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../mk/bsd.pkg.mk"
