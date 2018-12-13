# $NetBSD: Makefile,v 1.57 2018/12/13 19:52:06 adam Exp $
#

PLUGIN_NAME=	bogofilter
PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.1.7:../../mail/bogofilter

.include "../../mk/bsd.pkg.mk"
