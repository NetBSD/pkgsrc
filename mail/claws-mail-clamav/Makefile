# $NetBSD: Makefile,v 1.3 2007/09/23 17:08:01 joerg Exp $
#

PLUGIN_NAME=	clamav_plugin
PKGREVISION=	1
.include "../../mail/claws-mail/plugins.mk"
BUILD_DIRS=     src/plugins/clamav
INSTALL_DIRS=   src/plugins/clamav

MAINTAINER=	smb@NetBSD.org
COMMENT=	Enables the scanning of message attachments using Clam AntiVirus

CONFIGURE_ARGS+=	--enable-clamav-plugin

USE_LANGUAGES=	c

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail
DEPENDS+=	clamav>=0.91.1nb1:../../mail/clamav

.include "../../mail/claws-mail/Makefile.vers"
.include "../../mail/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
