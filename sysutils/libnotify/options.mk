# $NetBSD: options.mk,v 1.9 2023/02/14 14:03:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnotify
PKG_SUPPORTED_OPTIONS=	doc tests
PKG_SUGGESTED_OPTIONS=	# empty
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto
PLIST.doc=		yes
MESON_ARGS+=		-Ddocbook_docs=enabled
MESON_ARGS+=		-Dgtk_doc=true
.else
MESON_ARGS+=		-Ddocbook_docs=disabled
MESON_ARGS+=		-Dgtk_doc=false
.endif

.if !empty(PKG_OPTIONS:Mtests)
# 'make test' doesn't work:
#	[0/1] Running all tests.
#	No tests defined.
# though tests are built (see output/tests);
# also, running them manually, some of these need a DISPLAY
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}
MESON_ARGS+=		-Dtests=true
BUILDLINK_DEPMETHOD.gtk3=	build
.include "../../x11/gtk3/buildlink3.mk"
.else
MESON_ARGS+=		-Dtests=false
.endif
