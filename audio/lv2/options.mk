# $NetBSD: options.mk,v 1.5 2024/01/14 09:44:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lv2
PKG_SUPPORTED_OPTIONS=	doc tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
TOOL_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TOOL_DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
TOOL_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TOOL_DEPENDS+=	${PYPKGPREFIX}-rdflib-[0-9]*:../../textproc/py-rdflib
MESON_ARGS+=	-Ddocs=enabled

PLIST_SRC=	${PLIST_SRC_DFLT} PLIST.doc ${WRKDIR}/PLIST.STATIC

post-install: doxygen-plist
.PHONY: doxygen-plist
doxygen-plist:
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/lv2 -type f -print > ${WRKDIR}/PLIST.STATIC
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=	-Dtests=enabled
USE_LANGUAGES+=	c c++
.else
MESON_ARGS+=	-Dtests=disabled
.endif
