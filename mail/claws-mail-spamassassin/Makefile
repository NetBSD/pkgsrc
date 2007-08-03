# $NetBSD: Makefile,v 1.1 2007/08/03 02:34:59 smb Exp $
#

PLUGIN_NAME=	spamassassin
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.1:../../mail/spamassassin

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
