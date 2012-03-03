# $NetBSD: Makefile,v 1.23 2012/03/03 00:13:28 wiz Exp $
#

PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	pgpmime
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles PGP/MIME signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
