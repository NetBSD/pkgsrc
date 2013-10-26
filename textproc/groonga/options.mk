# $NetBSD: options.mk,v 1.5 2013/10/26 13:38:40 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.groonga
PKG_SUPPORTED_OPTIONS=	mecab tests zlib lzo
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
CONFIGURE_ARGS+=	--with-cutter
USE_TOOLS+=		gmake
TEST_TARGET=		check
TEST_ENV+=		RUBYOPT="-Ku"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_API_DEPENDS.cutter+=		cutter>=1.1.6
.include "../../devel/cutter/buildlink3.mk"
# XXX: no way to add build dependency on json
#RUBY_JSON_REQD=		1.8.0
#.include "../../lang/ruby/json.mk"
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-bundler-[0-9]*:../../misc/ruby-bundler
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-msgpack>=0.5.6:../../devel/ruby-msgpack
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-test-unit>=2.5.5:../../devel/ruby-msgpack
BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-test-unit-notify>=1.0.1:../../devel/ruby-test-unit-notify
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

.if !empty(PKG_OPTIONS:Mgroonga-httpd)
.include "../../devel/pcre/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-groonga-httpd
PLIST.httpd=	yes
OWN_DIRS+=	${PKG_SYSCONFDIR}/httpd/html
OWN_DIRS+=	${PKG_SYSCONFDIR}/httpd

CONF_FILES+=	share/examples/${PKGBASE}/httpd/fastcgi.conf \
		${PKG_SYSCONFDIR}/httpd/fastcgi.conf
CONF_FILES+=	share/examples/${PKGBASE}/httpd/fastcgi_params \
		${PKG_SYSCONFDIR}/httpd/fastcgi_params
CONF_FILES+=	share/examples/${PKGBASE}/httpd/groonga-httpd.conf \
		${PKG_SYSCONFDIR}/httpd/groonga-httpd.conf
CONF_FILES+=	share/examples/${PKGBASE}/httpd/html/50x.html \
		${PKG_SYSCONFDIR}/httpd/html/50x.html
CONF_FILES+=	share/examples/${PKGBASE}/httpd/html/index.html \
		${PKG_SYSCONFDIR}/httpd/html/index.html
CONF_FILES+=	share/examples/${PKGBASE}/httpd/koi-utf \
		${PKG_SYSCONFDIR}/httpd/koi-utf
CONF_FILES+=	share/examples/${PKGBASE}/httpd/koi-win \
		${PKG_SYSCONFDIR}/httpd/koi-win
CONF_FILES+=	share/examples/${PKGBASE}/httpd/mime.types \
		${PKG_SYSCONFDIR}/httpd/mime.types
CONF_FILES+=	share/examples/${PKGBASE}/httpd/scgi_params \
		${PKG_SYSCONFDIR}/httpd/scgi_params
CONF_FILES+=	share/examples/${PKGBASE}/httpd/uwsgi_params \
		${PKG_SYSCONFDIR}/httpd/uwsgi_params
CONF_FILES+=	share/examples/${PKGBASE}/httpd/win-utf \
		${PKG_SYSCONFDIR}/httpd/win-utf

SUBST_CLASSES+=		confpath
SUBST_STAGE.confpath=	post-configure
SUBST_FILES.confpath=	vendor/nginx-1.4.2/objs/Makefile
SUBST_SED.confpath=	-e 's,\$$(DESTDIR)${PKG_SYSCONFDIR}/httpd,\$$(DESTDIR)${PREFIX}/share/examples/${PKGBASE}/httpd,g'
.else
CONFIGURE_ARGS+=	--disable-groonga-httpd
.endif
