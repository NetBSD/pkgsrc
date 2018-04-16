# $NetBSD: Makefile,v 1.48 2018/04/16 14:34:49 wiz Exp $
#

PLUGIN_NAME=	spamassassin
PKGREVISION= 5
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.5:../../mail/spamassassin

.include "../../mk/bsd.pkg.mk"
