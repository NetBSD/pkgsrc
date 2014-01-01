# $NetBSD: plugins.mk,v 1.5 2014/01/01 11:43:24 wiz Exp $
#
# used by mail/claws-mail-bogofilter/Makefile
# used by mail/claws-mail-pgpcore/Makefile
# used by mail/claws-mail-pgpinline/Makefile
# used by mail/claws-mail-pgpmime/Makefile
# used by mail/claws-mail-smime/Makefile
# used by mail/claws-mail-spamassassin/Makefile

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
