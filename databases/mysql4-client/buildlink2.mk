# $NetBSD: buildlink2.mk,v 1.2 2004/03/26 02:27:36 wiz Exp $

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mysql-client
BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=4.0.17
BUILDLINK_RECOMMENDED.mysql-client?=	mysql-client>=4.0.18nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql4-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=	include/mysql/*.h
BUILDLINK_FILES.mysql-client+=	lib/mysql/libmysqlclient.*

FIX_RPATH+=	BUILDLINK_LDFLAGS.mysql-client
BUILDLINK_LDFLAGS.mysql-client= \
	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql			\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql-client-buildlink

mysql-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
