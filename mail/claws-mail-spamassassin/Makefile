# $NetBSD: Makefile,v 1.24 2012/12/16 01:52:19 obache Exp $
#

PLUGIN_NAME=	spamassassin
PKGREVISION=	2
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using SpamAssassin

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	spamassassin>=3.2.5:../../mail/spamassassin

.include "../../mail/claws-mail/Makefile.vers"

.include "../../mk/bsd.pkg.mk"
