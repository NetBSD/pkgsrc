# $NetBSD: options.mk,v 1.1 2005/08/30 16:14:53 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lbdb
PKG_SUPPORTED_OPTIONS=	osx-addressbook gnupg abook
PKG_SUGGESTED_OPTIONS= gnupg abook

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mosx-addressbook)
CONFIGURE_ARGS+=	--with-osx-addressbook
PLIST_SUBST+= OSXADDRESSBOOK=""
.else
CONFIGURE_ARGS+=	--without-osx-addressbook
PLIST_SUBST+= OSXADDRESSBOOK="@comment "
.endif

.if !empty(PKG_OPTIONS:Mgnupg)
DEPENDS=gnupg-[0-9]*:../../security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST_SUBST+= WITHGPG=""
.else
CONFIGURE_ARGS+=	--without-gpg
PLIST_SUBST+= WITHGPG="@comment "
.endif

.if !empty(PKG_OPTIONS:Mabook)
DEPENDS=abook-[0-9]*:../../databases/abook
CONFIGURE_ARGS+=	--with-abook
PLIST_SUBST+= WITHABOOK=""
.else
CONFIGURE_ARGS+=	--without-abook
PLIST_SUBST+= WITHABOOK="@comment "
.endif
