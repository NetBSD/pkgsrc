# $NetBSD: plugins.mk,v 1.3 2004/04/27 07:19:04 cube Exp $
#

.include "../../mail/sylpheed-claws/Makefile.common"

PKGNAME=	sylpheed-claws-${PLUGIN_NAME:S/_/-/}-${SYLPHEED_VERSION}

WRKSRC=		${WRKDIR}/${DISTNAME}/src/plugins/${PLUGIN_NAME}
CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}

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

PLIST_SRC=	${.CURDIR}/../../mail/sylpheed-claws/PLIST.plugins
PLIST_SUBST+=	PLUGIN_NAME=${PLUGIN_NAME}

MESSAGE_SRC+=	${.CURDIR}/../../mail/sylpheed-claws/MESSAGE.plugins
