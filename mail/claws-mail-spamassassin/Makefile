# $NetBSD: Makefile,v 1.78 2022/08/11 05:08:57 gutteridge Exp $
#

PLUGIN_NAME=	spamassassin

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.5:../../mail/spamassassin

.include "../../mk/bsd.pkg.mk"
