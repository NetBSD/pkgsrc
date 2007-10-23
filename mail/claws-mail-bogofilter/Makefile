# $NetBSD: Makefile,v 1.4 2007/10/23 20:16:51 smb Exp $
#

PLUGIN_NAME=	bogofilter
PLUG_VER=	3.0.1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter
PKGREVISION=	2

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail>=3.0.1:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.0.3nb1:../../mail/bogofilter

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
