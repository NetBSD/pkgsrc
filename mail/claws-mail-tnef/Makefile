# $NetBSD: Makefile,v 1.44 2016/08/03 10:23:05 adam Exp $
#

PLUGIN_NAME=    tnef_parse
PKGREVISION= 2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Handles TNEF attachments from Outlook

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
