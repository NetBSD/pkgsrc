# $NetBSD: Makefile,v 1.1.1.1 2008/11/15 18:28:56 jmcneill Exp $
#

DISTNAME=		system-tools-backends-2.6.0
CATEGORIES=		sysutils
MASTER_SITES=		http://system-tools-backends.freedesktop.org/downloads/2.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://system-tools-backends.freedesktop.org/
COMMENT=		DBus interface for system configuration

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-stb-group=${ROOT_GROUP}
CONFIGURE_ARGS+=	--localstatedir=/var

DEPENDS+=	p5-XML-Twig>=3.32:../../textproc/p5-XML-Twig
DEPENDS+=	p5-Net-DBus>=0.33.6:../../net/p5-Net-DBus
DEPENDS+=	p5-libwww>=5.820:../../www/p5-libwww
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
