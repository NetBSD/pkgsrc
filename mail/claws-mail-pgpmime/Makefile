# $NetBSD: Makefile,v 1.5 2008/01/09 03:55:12 smb Exp $
#

PLUGIN_NAME=	pgpmime
PLUG_VER=	3.2.0
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles PGP/MIME signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin

DEPENDS+=	claws-mail-pgpcore-3.2.0{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
