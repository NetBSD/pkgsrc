# $NetBSD: plugins.mk,v 1.3 2008/10/15 16:22:02 smb Exp $
#

.include "../../mail/claws-mail/Makefile.common"
.include "../../mail/claws-mail/Makefile.vers"

PKGNAME=	claws-mail-${PLUGIN_NAME:S/_/-/}-${CLAWS_VERSION}

CONFIGURE_DIRS=	.
BUILD_DIRS=	src/plugins/${PLUGIN_NAME}
INSTALL_DIRS=	src/plugins/${PLUGIN_NAME}

LIBTOOL_OVERRIDE=	../../../libtool

#.include "../../mail/claws-mail/options.mk"

PLIST_SRC=	${.CURDIR}/../../mail/claws-mail/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=${PLUGIN_NAME:Q}

MESSAGE_SRC+=	${.CURDIR}/../../mail/claws-mail/MESSAGE.plugins
