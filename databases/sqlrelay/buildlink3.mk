# $NetBSD: buildlink3.mk,v 1.1 2014/05/22 12:50:48 fhajny Exp $

BUILDLINK_TREE+=	sqlrelay

.if !defined(SQLRELAY_BUILDLINK3_MK)
SQLRELAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlrelay+=	sqlrelay>=0.43
BUILDLINK_PKGSRCDIR.sqlrelay?=		../../databases/sqlrelay

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/rudiments/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif	# SQLRELAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlrelay
