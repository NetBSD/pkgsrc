# $NetBSD: Makefile,v 1.87 2022/08/11 05:08:57 gutteridge Exp $
#

PLUGIN_NAME=    tnef_parse

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mail/libytnef/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
