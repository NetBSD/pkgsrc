# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:34:10 wiz Exp $

BUILDLINK_TREE+=	erlang21

.if !defined(ERLANG21_BUILDLINK3_MK)
ERLANG21_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erlang21+=	erlang21>=21
BUILDLINK_ABI_DEPENDS.erlang21+=	erlang21>=21.3.6nb2
BUILDLINK_PKGSRCDIR.erlang21?=		../../lang/erlang21

pkgbase := erlang21
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.erlang21:Miodbc}
.  include "../../databases/iodbc/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.erlang21:Munixodbc}
.  include "../../databases/unixodbc/buildlink3.mk"
.endif

.endif # ERLANG21_BUILDLINK3_MK

BUILDLINK_TREE+=	-erlang21
