# $NetBSD: options.mk,v 1.4 2019/02/08 22:25:32 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lbdb
PKG_SUPPORTED_OPTIONS=	osx-addressbook gnupg abook
PKG_SUGGESTED_OPTIONS=	gnupg abook

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		osx-addressbook gnupg abook

.if !empty(PKG_OPTIONS:Mosx-addressbook)
CONFIGURE_ARGS+=	--with-osx-addressbook
PLIST.osx-addressbook=	yes
.else
CONFIGURE_ARGS+=	--without-osx-addressbook
.endif

.if !empty(PKG_OPTIONS:Mgnupg)
DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
CONFIGURE_ARGS+=	--with-gpg
PLIST.gnupg=		yes
.else
CONFIGURE_ARGS+=	--without-gpg
.endif

.if !empty(PKG_OPTIONS:Mabook)
DEPENDS+=		abook-[0-9]*:../../databases/abook
CONFIGURE_ARGS+=	--with-abook
PLIST.abook=		yes
.else
CONFIGURE_ARGS+=	--without-abook
.endif
