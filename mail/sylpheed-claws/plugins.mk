# $NetBSD: plugins.mk,v 1.5 2005/03/06 16:45:47 chris Exp $
#

.include "../../mail/sylpheed-claws/Makefile.common"

PKGNAME=	sylpheed-claws-${PLUGIN_NAME:S/_/-/}-${SYLPHEED_VERSION}

BUILD_DIRS=	${WRKDIR}/${DISTNAME}/src/plugins/${PLUGIN_NAME}
CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}
INSTALL_DIRS=	${WRKDIR}/${DISTNAME}/src/plugins/${PLUGIN_NAME}

DEPENDS+=       sylpheed-claws>=${SYLPHEED_VERSION}:../../mail/sylpheed-claws

LIBTOOL_OVERRIDE=	../../../libtool

CONFIGURE_ARGS+=        --disable-aspell
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-openssl
CONFIGURE_ARGS+=	--disable-gpgme
CONFIGURE_ARGS+=	--disable-compface
CONFIGURE_ARGS+=	--disable-ipv6
CONFIGURE_ARGS+=	--disable-trayicon-plugin
CONFIGURE_ARGS+=	--disable-image-viewer-plugin
CONFIGURE_ARGS+=	--disable-clamav-plugin
CONFIGURE_ARGS+=	--disable-dillo-viewer-plugin
CONFIGURE_ARGS+=	--disable-spamassassin-plugin
CONFIGURE_ARGS+=	--disable-mathml-viewer-plugin
CONFIGURE_ARGS+=	--disable-pgpmime-plugin

PLIST_SRC=	${.CURDIR}/../../mail/sylpheed-claws/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=${PLUGIN_NAME}

MESSAGE_SRC+=	${.CURDIR}/../../mail/sylpheed-claws/MESSAGE.plugins
