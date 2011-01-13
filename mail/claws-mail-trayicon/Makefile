# $NetBSD: Makefile,v 1.15 2011/01/13 13:40:11 wiz Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	trayicon
.include "../../mail/claws-mail/plugins.mk"
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Places an icon in the system tray for new mail

CONFIGURE_ARGS+=	--enable-trayicon-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"

.include "../../mk/bsd.pkg.mk"
