# $NetBSD: Makefile,v 1.81 2021/07/13 12:35:09 nia Exp $
#

PLUGIN_NAME=    att_remover

.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Permanently deletes attachments from mail

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
