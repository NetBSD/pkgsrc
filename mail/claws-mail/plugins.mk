# $NetBSD: plugins.mk,v 1.1 2007/08/03 02:34:41 smb Exp $
#

.include "../../mail/claws-mail/Makefile.common"

PKGNAME=	claws-mail-${PLUGIN_NAME:S/_/-/}-${CLAWS_VERSION}

CONFIGURE_DIRS=	.
BUILD_DIRS=	src/plugins/${PLUGIN_NAME}
INSTALL_DIRS=	src/plugins/${PLUGIN_NAME}

DEPENDS+=       claws-mail>=${CLAWS_VERSION}:../../mail/claws-mail

LIBTOOL_OVERRIDE=	../../../libtool

#.include "../../mail/claws-mail/options.mk"

PLIST_SRC=	${.CURDIR}/../../mail/claws-mail/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=${PLUGIN_NAME:Q}

MESSAGE_SRC+=	${.CURDIR}/../../mail/claws-mail/MESSAGE.plugins
