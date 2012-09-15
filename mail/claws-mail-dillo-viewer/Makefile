# $NetBSD: Makefile,v 1.26 2012/09/15 10:05:23 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	dillo_viewer
PKGREVISION=	1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Plugin to use the Dillo web browser for html rendering

CONFIGURE_ARGS+=	--enable-dillo_viewer-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	dillo>=2.0:../../www/dillo

.include "../../mail/claws-mail/Makefile.vers"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
