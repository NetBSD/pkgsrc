# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:26 jlam Exp $

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mysql-client
BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.22
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=	include/mysql/*.h
BUILDLINK_FILES.mysql-client+=	lib/mysql/libmysqlclient.*

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql-client-buildlink

mysql-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
