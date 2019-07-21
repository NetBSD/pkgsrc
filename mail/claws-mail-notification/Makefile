# $NetBSD: Makefile,v 1.68 2019/07/21 22:25:16 wiz Exp $
#

PLUGIN_NAME=    notification
PKGREVISION= 7
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provides various ways to notify the user of new and unread email

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
