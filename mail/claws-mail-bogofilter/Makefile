# $NetBSD: Makefile,v 1.5 2008/01/09 03:55:10 smb Exp $
#

PLUGIN_NAME=	bogofilter
PLUG_VER=	3.2.0
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.0.3nb1:../../mail/bogofilter

.include "../../mail/claws-mail/Makefile.vers"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
