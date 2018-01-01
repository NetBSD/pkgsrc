# $NetBSD: Makefile,v 1.50 2018/01/01 21:18:38 adam Exp $
#

PLUGIN_NAME=    archive
PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Adds archiving to Claws-Mail

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
