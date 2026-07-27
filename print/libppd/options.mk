# $NetBSD: options.mk,v 1.1 2026/07/27 19:16:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libppd

# pdftops-renderers: PDF-to-PS renderers to include support for
# pdftops-renderer: default PDF-to-PS renderer to use
#  when CUPS option pdftops-renderer is not set
PKG_OPTIONS_REQUIRED_GROUPS+=		pdftops-renderer
PKG_OPTIONS_NONEMPTY_SETS+=		pdftops-renderers
.for i in gs pdftops pdftocairo mupdf # hybrid
PKG_OPTIONS_SET.pdftops-renderers+=	pdftops-renderers-${i}
PKG_OPTIONS_GROUP.pdftops-renderer+=	pdftops-renderer-${i}
.endfor
PKG_SUGGESTED_OPTIONS+=			pdftops-renderers-gs pdftops-renderers-pdftops
PKG_SUGGESTED_OPTIONS+=			pdftops-renderer-gs

.include "../../mk/bsd.options.mk"

PDFTOPS_RENDERER=	${PKG_OPTIONS:Mpdftops-renderer-*:S/^pdftops-renderer-//}
.if !empty(PKG_OPTIONS:Mpdftops-renderers-${PDFTOPS_RENDERER})
CONFIGURE_ARGS+=	--with-pdftops=${PDFTOPS_RENDERER}
.else
PKG_FAIL_REASON+=	"Default pdftops renderer ${PDFTOPS_RENDERER} not included in pdftops renderers"
.endif

# Strangely, for some of the possible renderers, there's a
#  --disable-xxx option, for some, you need to revert to
#  passing a nonexistent path
.if !empty(PKG_OPTIONS:Mpdftops-renderers-gs)
.include "../../print/ghostscript/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gs-path=${PREFIX}/bin/gs
.else
CONFIGURE_ARGS+=	--disable-ghostscript
.endif

.if !empty(PKG_OPTIONS:Mpdftops-renderers-pdftops)
DEPENDS+=		poppler-utils-[0-9]*:../../print/poppler-utils
CONFIGURE_ARGS+=	--with-pdftops-path=${PREFIX}/bin/pdftops
.else
CONFIGURE_ARGS+=	--with-pdftops-path=/nonexistent/pdftops
.endif

.if !empty(PKG_OPTIONS:Mpdftops-renderers-pdftocairo)
DEPENDS+=		poppler-utils-[0-9]*:../../print/poppler-utils
CONFIGURE_ARGS+=	--with-pdftocairo-path=${PREFIX}/bin/pdftocairo
.else
CONFIGURE_ARGS+=	--with-pdftocairo-path=/nonexistent/pdftocairo
.endif

.if !empty(PKG_OPTIONS:Mpdftops-renderers-mupdf)
DEPENDS+=		mupdf-[0-9]*:../../print/mupdf
CONFIGURE_ARGS+=	--with-mutool-path=${PREFIX}/bin/mutool
.else
CONFIGURE_ARGS+=	--disable-mutool
.endif
