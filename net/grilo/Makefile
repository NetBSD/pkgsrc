# $NetBSD: Makefile,v 1.1 2012/11/23 11:51:14 drochner Exp $
#

DISTNAME=	grilo-0.2.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/grilo/0.2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Media browser framework
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

PKGCONFIG_OVERRIDE+=	grilo-0.2.pc.in
PKGCONFIG_OVERRIDE+=	grilo-net-0.2.pc.in

# gtk3 for test app only
#.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
