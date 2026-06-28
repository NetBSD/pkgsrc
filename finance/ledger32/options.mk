# $NetBSD: options.mk,v 1.4 2026/06/28 19:59:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ledger
PKG_SUPPORTED_OPTIONS+=	python
PKG_SUGGESTED_OPTIONS+=

PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
BROKEN=		"does not support Python > 3.11 but py-numpy does not support < 3.12"

# https://github.com/ledger/ledger/issues/2332
PYTHON_VERSIONS_ACCEPTED=	311 # PyUnicode_GET_SIZE

CMAKE_CONFIGURE_ARGS+=		-DUSE_PYTHON:BOOL=TRUE
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
.include "../../devel/py-boost/buildlink3.mk"

# Remove when src/CMakeLists.txt (see FIXME there) stops copying
# uninstalled library as Python module. Make symlink here to
# avoid problem with install_name on Darwin and save disk-space.
post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB} && \
	${LN} -s -f ${DESTDIR}${PREFIX}/lib/libledger.${SHLIB_EXT} ledger.so
.endif
