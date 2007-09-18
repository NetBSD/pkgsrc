# $NetBSD: Makefile,v 1.2 2007/09/18 03:17:29 smb Exp $
#

PLUGIN_NAME=	pgpinline
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles PGP/Inline signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
