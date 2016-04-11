# $NetBSD: options.mk,v 1.4 2016/04/11 04:22:33 dbj Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.git
PKG_SUPPORTED_OPTIONS=	python apple-common-crypto
# python is not suggested because upstream's INSTALL does not list python
# as a dependency and because all it does is install a python module,
# which does not seem worth the dependency for everyone else.
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		python

.if !empty(PKG_OPTIONS:Mpython)
PY_PATCHPLIST=	yes
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PLIST.python=		yes
# not executable
CHECK_INTERPRETER_SKIP+= ${PYSITELIB}/git_remote_helpers/*.py
CHECK_INTERPRETER_SKIP+= ${PYSITELIB}/git_remote_helpers/git/*.py
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if !empty(PKG_OPTIONS:Mapple-common-crypto)
.  if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
PKG_FAIL_REASON+=	"apple-common-crypto not available on this system"
.  endif
CONFIGURE_ARGS+=	--without-openssl
.else
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"
MAKE_FLAGS+=		NO_APPLE_COMMON_CRYPTO=1
.endif
