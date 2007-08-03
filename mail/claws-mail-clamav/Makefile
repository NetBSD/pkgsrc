# $NetBSD: Makefile,v 1.1 2007/08/03 02:34:43 smb Exp $
#

PLUGIN_NAME=	clamav_plugin
.include "../../mail/claws-mail/plugins.mk"
BUILD_DIRS=     src/plugins/clamav
INSTALL_DIRS=   src/plugins/clamav

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of message attachments using Clam AntiVirus

CONFIGURE_ARGS+=	--enable-clamav-plugin

USE_LANGUAGES=	c

DEPENDS+=	claws-mail>=2.10.0:../../mail/claws-mail
DEPENDS+=	clamav>=0.91.1nb1:../../mail/clamav

.include "../../mail/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
