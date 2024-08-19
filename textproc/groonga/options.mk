# $NetBSD: options.mk,v 1.20 2024/08/19 11:55:25 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga
PKG_SUPPORTED_OPTIONS=	lz4 mecab tests zstd
PKG_SUPPORTED_OPTIONS+=	groonga-suggest-learner
PKG_SUGGESTED_OPTIONS=	mecab groonga-suggest-learner

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mecab learner

.if !empty(PKG_OPTIONS:Mmecab)
CONFIGURE_ARGS+=	--with-mecab
CONFIGURE_ARGS+=	--with-mecab-config=${BUILDLINK_PREFIX.mecab}/bin/mecab-config
.include "../../textproc/mecab/buildlink3.mk"
PLIST.mecab=		yes
.else
CONFIGURE_ARGS+=	--without-mecab
.endif

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=		check
BUILDLINK_API_DEPENDS.cutter+=		cutter>=1.1.6
.include "../../devel/cutter/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mzstd)
CONFIGURE_ARGS+=	--with-zstd
.include "../../archivers/zstd/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zstd
.endif

.if !empty(PKG_OPTIONS:Mlz4)
CONFIGURE_ARGS+=	--with-lz4
.include "../../archivers/lz4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lz4
.endif

.if !empty(PKG_OPTIONS:Mgroonga-suggest-learner)
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-message-pack=${BUILDLINK_PREFIX.msgpack}
CONFIGURE_ARGS+=	--enable-zeromq
PLIST.learner=		yes
.else
CONFIGURE_ARGS+=	--without-libevent
CONFIGURE_ARGS+=	--without-message-pack
CONFIGURE_ARGS+=	--disable-zeromq
.endif
