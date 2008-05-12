# $NetBSD: Makefile,v 1.7 2008/05/12 02:25:40 smb Exp $
#

PLUGIN_NAME=	pgpcore
PLUG_VER=	3.4.0
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles core PGP functions

PLIST_SRC+=	PLIST

PLIST_SRC+=	PLIST

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-3.4.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	gnupg>=1.4.9:../../security/gnupg
DEPENDS+=	gpgme>=1.1.4nb2:../../security/gpgme

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
