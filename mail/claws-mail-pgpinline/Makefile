# $NetBSD: Makefile,v 1.30 2012/12/16 01:52:18 obache Exp $
#

PLUGIN_NAME=	pgpinline
PKGREVISION=	4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles PGP/Inline signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
