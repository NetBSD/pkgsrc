# $NetBSD: Makefile,v 1.87 2022/10/26 10:31:37 wiz Exp $

PLUGIN_NAME=	pgpmime

.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles PGP/MIME signed and/or encrypted mails
PKGREVISION=	5

CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
