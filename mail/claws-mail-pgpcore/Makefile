# $NetBSD: Makefile,v 1.5 2007/10/23 20:16:53 smb Exp $
#

PLUGIN_NAME=	pgpcore
PLUG_VER=	3.0.1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles core PGP functions
PKGREVISION=	2

PLIST_SRC+=	PLIST

PLIST_SRC+=	PLIST

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail>=3.0.1:../../mail/claws-mail
DEPENDS+=	gnupg>=1.4.7:../../security/gnupg
DEPENDS+=	gpgme>=1.1.4:../../security/gpgme

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
