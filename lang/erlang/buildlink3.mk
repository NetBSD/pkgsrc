# $NetBSD: buildlink3.mk,v 1.18 2023/01/11 23:18:25 nikita Exp $

BUILDLINK_TREE+=	erlang

.if !defined(ERLANG_BUILDLINK3_MK)
ERLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erlang+=	erlang>=10.1
BUILDLINK_ABI_DEPENDS.erlang+=	erlang>=25.2nb1
BUILDLINK_PKGSRCDIR.erlang?=	../../lang/erlang

pkgbase := erlang
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.erlang:Miodbc}
.  include "../../databases/iodbc/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.erlang:Munixodbc}
.  include "../../databases/unixodbc/buildlink3.mk"
.endif

.endif # ERLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-erlang
