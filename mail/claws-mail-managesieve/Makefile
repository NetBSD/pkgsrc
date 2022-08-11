# $NetBSD: Makefile,v 1.45 2022/08/11 05:08:56 gutteridge Exp $
#

PLUGIN_NAME=    managesieve

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage Sieve filters on servers that support the ManageSieve protocol

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
