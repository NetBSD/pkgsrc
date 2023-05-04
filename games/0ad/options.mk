# $NetBSD: options.mk,v 1.1 2023/05/04 15:20:52 nikita Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.0ad
PKG_SUPPORTED_OPTIONS+=	tests editor

PLIST_VARS+=		editor tests

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
CONFIGURE_TESTS?=
PLIST.tests=			yes
.else
CONFIGURE_TESTS?=		--without-tests
.endif

# TODO: not entirely working binary (loads, complains about files not found),
# something is missing.
.if ${PKG_OPTIONS:Meditor}
CONFIGURE_EDITOR?=
.include "../../x11/wxGTK32/buildlink3.mk"
PLIST.editor=			yes
.else
CONFIGURE_EDITOR?=		--disable-atlas
.endif
