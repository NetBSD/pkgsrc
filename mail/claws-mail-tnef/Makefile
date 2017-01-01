# $NetBSD: Makefile,v 1.48 2017/01/01 16:06:25 adam Exp $
#

PLUGIN_NAME=    tnef_parse
PKGREVISION= 3
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
