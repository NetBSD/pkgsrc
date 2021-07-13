# $NetBSD: Makefile,v 1.1 2021/07/13 12:35:10 nia Exp $
#

PLUGIN_NAME=    dillo

.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables viewing HTML messages using the Dillo web browser

DEPENDS+=	dillo-[0-9]*:../../www/dillo

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
