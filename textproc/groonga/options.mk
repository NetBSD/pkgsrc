# $NetBSD: options.mk,v 1.3 2012/02/27 11:59:52 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga
PKG_SUPPORTED_OPTIONS=	mecab tests zlib lzo groonga-suggest-learner
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
CONFIGURE_ARGS+=	--with-cutter
USE_TOOLS+=		gmake
TEST_TARGET=		check
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_API_DEPENDS.cutter+=		cutter>=1.1.6
.include "../../devel/cutter/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-cutter
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
.endif

.if !empty(PKG_OPTIONS:Mlzo)
CONFIGURE_ARGS+=	--with-lzo
.include "../../archivers/lzo/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-lzo
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
