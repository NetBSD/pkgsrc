# $NetBSD: buildlink3.mk,v 1.13 2015/04/28 14:34:20 fhajny Exp $

BUILDLINK_TREE+=	erlang

.if !defined(ERLANG_BUILDLINK3_MK)
ERLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erlang+=	erlang>=10.1
BUILDLINK_ABI_DEPENDS.erlang+=	erlang>=17.5
BUILDLINK_PKGSRCDIR.erlang?=	../../lang/erlang

pkgbase := erlang
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.erlang:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.erlang:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.endif

.endif # ERLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-erlang
