# $NetBSD: options.mk,v 1.3 2023/05/05 00:08:13 nikita Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.0ad
PKG_SUPPORTED_OPTIONS+=	tests editor

PLIST_VARS+=		editor tests

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CONFIGURE_TESTS?=
PYTHON_VERSIONS_INCOMPATIBLE=	27
TOOL_DEPENDS+=			python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT}
PLIST.tests=			yes
.else
CONFIGURE_TESTS?=		--without-tests
.endif

# TODO: not entirely working binary (loads, complains about files not found),
# something is missing.
.if ${PKG_OPTIONS:Meditor}
CONFIGURE_EDITOR?=		--enable-atlas
.include "../../x11/wxGTK32/buildlink3.mk"
PLIST.editor=			yes
.else
CONFIGURE_EDITOR?=		--disable-atlas
.endif
