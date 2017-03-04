# $NetBSD: Makefile,v 1.52 2017/03/04 01:51:05 mef Exp $
#

PLUGIN_NAME=    notification
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides various ways to notify the user of new and unread email

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

PLIST_SRC+=	PLIST

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
