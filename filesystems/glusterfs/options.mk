# $NetBSD: options.mk,v 1.6 2011/12/09 16:57:44 manu Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.glusterfs
PKG_SUPPORTED_OPTIONS=  georeplication ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoreplication)
CONFIGURE_ARGS+=	--enable-georeplication
PLIST_SRC+=		${PKGDIR}/PLIST.georeplication
.else
CONFIGURE_ARGS+=       --disable-georeplication
.endif

.if !empty(PKG_OPTIONS:Mssl)
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.ssl
USE_TOOLS+=	patch
SSL_PATCH=	${FILESDIR}/ssl.patch
OPENSSL_SYSCONFDIR?=	${PKG_SYSCONFDIR}/openssl
CFLAGS+=	-DDEFAULT_CERT_PATH=\"${OPENSSL_SYSCONFDIR}/certs/gluster.crt\"
CFLAGS+=	-DDEFAULT_KEY_PATH=\"${OPENSSL_SYSCONFDIR}/private/gluster.key\"
CFLAGS+=	-DDEFAULT_CA_PATH=\"${OPENSSL_SYSCONFDIR}/certs/gluster-ca.crt\"
post-patch:
	${PATCH} -d ${WRKSRC} --forward --quiet  < ${SSL_PATCH}
.endif

