# $NetBSD: Makefile,v 1.7 2023/01/03 17:37:46 wiz Exp $
#

PLUGIN_NAME=    libravatar

PKGREVISION= 6
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Displays libravatar/gravatar profile images

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
