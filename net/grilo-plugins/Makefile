# $NetBSD: Makefile,v 1.21 2017/04/22 21:03:48 adam Exp $
#

DISTNAME=	grilo-plugins-0.2.9
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/grilo-plugins/0.2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Plugins for grilo media browser
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool xgettext

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
