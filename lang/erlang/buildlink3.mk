# $NetBSD: buildlink3.mk,v 1.9 2009/12/15 12:07:57 asau Exp $

BUILDLINK_TREE+=	erlang

.if !defined(ERLANG_BUILDLINK3_MK)
ERLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erlang+=	erlang>=10.1
BUILDLINK_ABI_DEPENDS.erlang?=	erlang>=10.1.9nb1
BUILDLINK_PKGSRCDIR.erlang?=	../../wip/erlang

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
