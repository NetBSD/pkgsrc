# $NetBSD: options.mk,v 1.4 2020/06/15 16:54:38 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ledger
PKG_SUPPORTED_OPTIONS+=	python
PKG_SUGGESTED_OPTIONS+=	python

PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=TRUE
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
.include "../../devel/py-boost/buildlink3.mk"

.  include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == "Darwin"
SOEXT=dylib
.  else
SOEXT=so
.  endif

# Remove when src/CMakeLists.txt (see FIXME there) stops copying
# uninstalled library as Python module. Make symlink here to
# avoid problem with install_name on Darwin and save disk-space.
post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB} && \
	${LN} -s -f ${DESTDIR}${PREFIX}/lib/libledger.${SOEXT} ledger.so
.endif
