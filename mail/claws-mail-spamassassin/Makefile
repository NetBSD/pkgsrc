# $NetBSD: Makefile,v 1.2 2007/09/18 03:17:30 smb Exp $
#

PLUGIN_NAME=	spamassassin
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.1:../../mail/spamassassin

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
