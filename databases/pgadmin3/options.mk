# $NetBSD: options.mk,v 1.2 2015/08/05 15:29:00 richard Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.pgadmin3
PKG_SUPPORTED_OPTIONS=	pgadmin-db-designer doc zlib
PKG_OPTIONS_OPTIONAL_GROUPS= crypto
PKG_SUGGESTED_OPTIONS=	pgadmin-db-designer openssl
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt

.include "../../mk/bsd.options.mk"

PLIST_VARS=	doc

### Database Designer support
.if !empty(PKG_OPTIONS:Mpgadmin-db-designer)
CONFIGURE_ARGS+=	--enable-databasedesigner
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx>=1.0:../../textproc/py-sphinx
CONFIGURE_ARGS+=		--with-sphinx-build=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}
.else
CONFIGURE_ENV+=		ac_cv_path_SPHINX_BUILD=
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
CONFIGURE_ARGS+=	--with-libgcrypt
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
.include "../../security/libgcrypt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libgcrypt
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-libssl-prefix=${BUILDLINK_PREFIX.openssl}
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-libz
CONFIGURE_ARGS+=	--with-libz-prefix=${BUILDLINK_PREFIX.zlib}
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libz
.endif
