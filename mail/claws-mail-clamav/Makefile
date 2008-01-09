# $NetBSD: Makefile,v 1.5 2008/01/09 03:55:10 smb Exp $
#

PLUGIN_NAME=	clamav_plugin
PLUG_VER=	3.2.0
.include "../../mail/claws-mail/plugins.mk"
BUILD_DIRS=     src/plugins/clamav
INSTALL_DIRS=   src/plugins/clamav

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of message attachments using Clam AntiVirus

CONFIGURE_ARGS+=	--enable-clamav-plugin

USE_LANGUAGES=	c

DEPENDS+=	claws-mail-3.2.0{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	clamav>=0.92:../../mail/clamav

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
