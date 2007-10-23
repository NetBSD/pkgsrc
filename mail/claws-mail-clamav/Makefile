# $NetBSD: Makefile,v 1.4 2007/10/23 20:16:52 smb Exp $
#

PLUGIN_NAME=	clamav_plugin
PLUG_VER=	3.0.1
.include "../../mail/claws-mail/plugins.mk"
BUILD_DIRS=     src/plugins/clamav
INSTALL_DIRS=   src/plugins/clamav

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of message attachments using Clam AntiVirus
PKGREVISION=	2

CONFIGURE_ARGS+=	--enable-clamav-plugin

USE_LANGUAGES=	c

DEPENDS+=	claws-mail>=3.0.1:../../mail/claws-mail
DEPENDS+=	clamav>=0.91.1nb1:../../mail/clamav

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
