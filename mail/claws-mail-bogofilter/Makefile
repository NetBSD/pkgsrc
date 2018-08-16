# $NetBSD: Makefile,v 1.52 2018/08/16 18:54:57 adam Exp $
#

PLUGIN_NAME=	bogofilter
PKGREVISION= 8
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.1.7:../../mail/bogofilter

.include "../../mk/bsd.pkg.mk"
