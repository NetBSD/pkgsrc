# $NetBSD: Makefile,v 1.86 2022/10/26 10:31:36 wiz Exp $
#

PLUGIN_NAME=    att_remover

PKGREVISION= 5
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Permanently deletes attachments from mail

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
