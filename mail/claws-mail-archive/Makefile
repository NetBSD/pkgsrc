# $NetBSD: Makefile,v 1.43 2017/01/01 16:06:24 adam Exp $
#

PLUGIN_NAME=    archive
PKGREVISION= 3
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Adds archiving to Claws-Mail

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
