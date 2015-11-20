# $NetBSD: plugins.mk,v 1.7 2015/11/20 14:32:55 joerg Exp $
#
# used by mail/claws-mail-archive/Makefile
# used by mail/claws-mail-attachwarner/Makefile
# used by mail/claws-mail-attremover/Makefile
# used by mail/claws-mail-bogofilter/Makefile
# used by mail/claws-mail-fetchinfo/Makefile
# used by mail/claws-mail-mailmbox/Makefile
# used by mail/claws-mail-newmail/Makefile
# used by mail/claws-mail-notification/Makefile
# used by mail/claws-mail-pgpcore/Makefile
# used by mail/claws-mail-pgpinline/Makefile
# used by mail/claws-mail-pgpmime/Makefile
# used by mail/claws-mail-rssyl/Makefile
# used by mail/claws-mail-smime/Makefile
# used by mail/claws-mail-spamassassin/Makefile
# used by mail/claws-mail-spamreport/Makefile
# used by mail/claws-mail-tnef/Makefile
# used by mail/claws-mail-vcalendar/Makefile

.include "../../mail/claws-mail/Makefile.common"
.include "../../mail/claws-mail/Makefile.vers"

PKGNAME=	claws-mail-${PLUGIN_NAME:S/_/-/}-${CLAWS_VERSION}

PLUGIN_FILE?=	${PLUGIN_NAME}
CONFIGURE_DIRS=	.
BUILD_DIRS=	src/plugins/${PLUGIN_NAME}
INSTALL_DIRS=	src/plugins/${PLUGIN_NAME}

LIBTOOL_OVERRIDE=	../../../libtool

#.include "../../mail/claws-mail/options.mk"

PLIST_SRC=	${.CURDIR}/../../mail/claws-mail/PLIST.plugins
PLIST_SUBST+=	PLUGIN_FILE=${PLUGIN_FILE:Q}

MESSAGE_SRC+=	${.CURDIR}/../../mail/claws-mail/MESSAGE.plugins
