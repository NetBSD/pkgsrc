# $NetBSD: options.mk,v 1.7 2026/08/12 12:51:34 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lv2
PKG_SUPPORTED_OPTIONS=	doc gtk2
PKG_SUGGESTED_OPTIONS=	doc gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
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
.include "../../lang/python/tool.mk"
.else
MESON_ARGS+=	-Ddocs=disabled
.endif

PLIST_VARS+=	gtk2
.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk2=	yes
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.10
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2++=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
.endif
