# $NetBSD: options.mk,v 1.1 2024/05/16 15:14:26 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aerc
PKG_SUPPORTED_OPTIONS=	notmuch
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include Notmuch Support
###
.if !empty(PKG_OPTIONS:Mnotmuch)
.include "../../mail/notmuch/buildlink3.mk"
CGO_LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.notmuch}/lib -L${BUILDLINK_PREFIX.notmuch}/lib
GO_BUILD_TAGS=	-tags=notmuch
.endif
