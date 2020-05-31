# $NetBSD: options.mk,v 1.19 2020/05/31 14:43:14 rillig Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga
PKG_SUPPORTED_OPTIONS=	mecab tests zlib lz4
PKG_SUPPORTED_OPTIONS+=	groonga-suggest-learner groonga-httpd
PKG_SUGGESTED_OPTIONS=	mecab groonga-suggest-learner groonga-httpd

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mecab learner httpd

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

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zlib
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

.if !empty(PKG_OPTIONS:Mgroonga-httpd)
.include "../../devel/pcre/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-groonga-httpd
PLIST.httpd=	yes
OWN_DIRS+=	${PKG_SYSCONFDIR}/httpd/html
OWN_DIRS+=	${PKG_SYSCONFDIR}/httpd
OWN_DIRS+=	${VARBASE}/run/${PKGBASE}
OWN_DIRS+=	${VARBASE}/log/${PKGBASE}/httpd
BUILD_DEFS+=	VARBASE

CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/fastcgi.conf \
		${PKG_SYSCONFDIR}/httpd/fastcgi.conf
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/fastcgi_params \
		${PKG_SYSCONFDIR}/httpd/fastcgi_params
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/groonga-httpd.conf \
		${PKG_SYSCONFDIR}/httpd/groonga-httpd.conf
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/html/50x.html \
		${PKG_SYSCONFDIR}/httpd/html/50x.html
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/html/index.html \
		${PKG_SYSCONFDIR}/httpd/html/index.html
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/koi-utf \
		${PKG_SYSCONFDIR}/httpd/koi-utf
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/koi-win \
		${PKG_SYSCONFDIR}/httpd/koi-win
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/mime.types \
		${PKG_SYSCONFDIR}/httpd/mime.types
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/scgi_params \
		${PKG_SYSCONFDIR}/httpd/scgi_params
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/uwsgi_params \
		${PKG_SYSCONFDIR}/httpd/uwsgi_params
CONF_FILES+=	${EXAMPLE_CONF_DIR}/httpd/win-utf \
		${PKG_SYSCONFDIR}/httpd/win-utf

SUBST_CLASSES+=		confpath
SUBST_STAGE.confpath=	pre-build
SUBST_FILES.confpath=	vendor/nginx-*/objs/Makefile
SUBST_SED.confpath=	-e 's,\$$(DESTDIR)${PKG_SYSCONFDIR}/httpd,\$$(DESTDIR)${PREFIX}/share/examples/${PKGBASE}/httpd,g'

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/examples/groonga/httpd/*.default

.else
CONFIGURE_ARGS+=	--disable-groonga-httpd
.endif
