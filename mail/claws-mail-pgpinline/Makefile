# $NetBSD: Makefile,v 1.35 2013/07/24 15:29:22 drochner Exp $
#

PLUGIN_NAME=	pgpinline
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles PGP/Inline signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
