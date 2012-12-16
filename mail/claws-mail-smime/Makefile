# $NetBSD: Makefile,v 1.31 2012/12/16 01:52:19 obache Exp $
#

PLUGIN_NAME=	smime
PKGREVISION=	4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	This plugin handles S/MIME signed and/or encrypted mails

PLIST_SRC+=	PLIST

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-smime-plugin
CONFIGURE_ARGS+=	--enable-pgpcore-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
#DEPENDS+=	gpgme>=1.1.4nb2:../../security/gpgme


.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/claws-mail-pgpcore/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/gnupg2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
