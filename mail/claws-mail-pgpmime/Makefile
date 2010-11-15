# $NetBSD: Makefile,v 1.15 2010/11/15 22:57:45 abs Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	pgpmime
.include "../../mail/claws-mail/plugins.mk"

PKGREVISION=	3

MAINTAINER=	smb@NetBSD.org
COMMENT=	Handles PGP/MIME signed and/or encrypted mails

CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-pgpcore-plugin
CONFIGURE_ARGS+=	--enable-pgpmime-plugin

DEPENDS+=	claws-mail-pgpcore-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail-pgpcore

PLIST_SRC+=	PLIST

.include "../../security/gpgme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
