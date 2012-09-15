# $NetBSD: Makefile,v 1.22 2012/09/15 10:05:26 obache Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	trayicon
PKGREVISION=	1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Places an icon in the system tray for new mail

CONFIGURE_ARGS+=	--enable-trayicon-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/claws-mail/Makefile.vers"

.include "../../mk/bsd.pkg.mk"
