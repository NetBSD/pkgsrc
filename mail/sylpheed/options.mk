# $NetBSD: options.mk,v 1.6 2009/10/12 19:47:40 ahoka Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.sylpheed
PKG_SUPPORTED_OPTIONS=	jpilot ldap inet6 gpgme gtkspell
PKG_SUGGESTED_OPTIONS=	inet6 gpgme gtkspell

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

FACES_IS_INSTALLED!=	${PKG_INFO} -e faces || ${ECHO}
.if empty(FACES_IS_INSTALLED)
.  include "../../graphics/compface/buildlink3.mk"
.else
.  include "../../mail/faces/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--enable-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpilot)
CONFIGURE_ARGS+=	--enable-jpilot
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../comms/jpilot/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtkspell)
CONFIGURE_ARGS+=	--enable-gtkspell
. include "../../textproc/gtkspell/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtkspell
.endif

.if !empty(PKG_OPTIONS:Mgpgme)
CONFIGURE_ARGS+=	--enable-gpgme
. include "../../security/gpgme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif
