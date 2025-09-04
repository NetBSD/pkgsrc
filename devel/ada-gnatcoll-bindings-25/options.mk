# $NetBSD: options.mk,v 1.4 2025/09/04 09:24:55 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnatcoll-bindings-25
PKG_SUPPORTED_OPTIONS=		gnatcoll-cpp gmp iconv lzma openmp \
				readline syslog zlib
PKG_OPTIONS_OPTIONAL_GROUPS=	python
PKG_OPTIONS_GROUP.python=	python2 python3
PKG_SUGGESTED_OPTIONS=		gnatcoll-cpp gmp iconv lzma openmp \
				python3 readline syslog zlib

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnatcoll-cpp)
BINDINGS+=	cpp
.endif

.if !empty(PKG_OPTIONS:Mgmp)
.  include "../../devel/gmp/buildlink3.mk"
BINDINGS+=	gmp
.endif

.if !empty(PKG_OPTIONS:Miconv)
USE_GNU_ICONV=	yes
.  include "../../converters/libiconv/buildlink3.mk"
BINDINGS+=	iconv
.  if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099982
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	post-extract
SUBST_FILES.iconv=	iconv/iconv_support.c
SUBST_MESSAGE.iconv=	Fix parameter type in ${SUBST_FILES.iconv}
SUBST_SED.iconv=	-e 's/iconv(cd, inbuf,/iconv(cd, (const char **)inbuf,/'
.  endif
.endif

.if !empty(PKG_OPTIONS:Mlzma)
BINDINGS+=	lzma
.endif

.if !empty(PKG_OPTIONS:Mopenmp)
BINDINGS+=	omp
.endif

.if !empty(PKG_OPTIONS:Mpython2)
# Python 2 only binding
PYTHON_VERSIONS_ACCEPTED+=		27
.  include "../../lang/python/pyversion.mk"
BINDINGS+=	python
.endif

.if !empty(PKG_OPTIONS:Mpython3)
# Python 3 only binding
PYTHON_VERSIONS_INCOMPATIBLE+=		27
.  include "../../lang/python/pyversion.mk"
BINDINGS+=	python3
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.  include "../../devel/readline/buildlink3.mk"
BINDINGS+=	readline
.endif

.if !empty(PKG_OPTIONS:Msyslog)
BINDINGS+=	syslog
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
BINDINGS+=	zlib
.endif
