# $NetBSD: Makefile,v 1.23 2018/12/13 19:52:06 adam Exp $
#

PLUGIN_NAME=    managesieve
PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manage Sieve filters on servers that support the ManageSieve protocol

CONFIGURE_ARGS+= --enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../mk/bsd.pkg.mk"
