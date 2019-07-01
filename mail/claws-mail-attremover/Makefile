# $NetBSD: Makefile,v 1.63 2019/07/01 04:08:28 ryoon Exp $
#

PLUGIN_NAME=    att_remover
PKGREVISION= 5
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Permanently deletes attachments from mail

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
