# $NetBSD: plugins.mk,v 1.2 2007/10/23 20:16:51 smb Exp $
#

.include "../../mail/claws-mail/Makefile.common"

PKGNAME=	claws-mail-${PLUGIN_NAME:S/_/-/}-${PLUG_VER}

CONFIGURE_DIRS=	.
BUILD_DIRS=	src/plugins/${PLUGIN_NAME}
INSTALL_DIRS=	src/plugins/${PLUGIN_NAME}

LIBTOOL_OVERRIDE=	../../../libtool

#.include "../../mail/claws-mail/options.mk"

PLIST_SRC=	${.CURDIR}/../../mail/claws-mail/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=${PLUGIN_NAME:Q}

MESSAGE_SRC+=	${.CURDIR}/../../mail/claws-mail/MESSAGE.plugins
