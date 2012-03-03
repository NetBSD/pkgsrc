# $NetBSD: Makefile,v 1.21 2012/03/03 00:14:25 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	bogofilter
.include "../../mail/claws-mail/plugins.mk"

PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.1.7:../../mail/bogofilter

.include "../../mk/bsd.pkg.mk"
