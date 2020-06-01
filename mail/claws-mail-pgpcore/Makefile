# $NetBSD: Makefile,v 1.79 2020/06/01 20:01:18 rillig Exp $
#

PLUGIN_NAME=	pgpcore

PKGREVISION= 2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles core PGP functions

PLIST_SRC+=	PLIST

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin
CONFIGURE_ARGS+=	--enable-pgpinline-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
#DEPENDS+=	gnupg>=1.4.9:../../security/gnupg
DEPENDS+=	gpgme>=1.1.4nb2:../../security/gpgme

.include "../../mail/claws-mail/Makefile.vers"
.include "../../security/gpgme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
