# $NetBSD: options.mk,v 1.8 2026/06/11 07:31:38 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lilv
PKG_SUPPORTED_OPTIONS=	doc tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
MESON_ARGS+=	-Ddocs=enabled
PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>0:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxygen>0:../../textproc/py-sphinxygen
# different versions of Doxygen generate different files
PLIST_SRC=      ${PLIST_SRC_DFLT} ${WRKDIR}/PLIST.DOCS
.PHONY: doxygen-plist
post-install: doxygen-plist
doxygen-plist:
	${RM} -f ${WRKDIR}/PLIST.DOCS
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/lilv-0 -type f -print > ${WRKDIR}/PLIST.DOCS
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
.else
MESON_ARGS+=	-Dtests=disabled
.endif
