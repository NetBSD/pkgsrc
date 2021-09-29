# $NetBSD: Makefile,v 1.2 2021/09/29 19:00:53 adam Exp $
#

PLUGIN_NAME=    dillo

PKGREVISION= 1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables viewing HTML messages using the Dillo web browser

DEPENDS+=	dillo-[0-9]*:../../www/dillo

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
