# $NetBSD: Makefile,v 1.9 2008/09/26 17:51:17 smb Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

PLUGIN_NAME=	bogofilter
PLUG_VER=	3.5.0
PKGREVISION=	1
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of incoming mail using Bogofilter

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-3.5.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	bogofilter>=1.0.3nb1:../../mail/bogofilter

.include "../../mail/claws-mail/Makefile.vers"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
