# $NetBSD: buildlink2.mk,v 1.6 2003/09/28 09:03:52 jdolecek Exp $

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mysql-client
BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.51nb1
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=	include/mysql/*.h
BUILDLINK_FILES.mysql-client+=	lib/mysql/libmysqlclient.*

FIX_RPATH+=	BUILDLINK_LDFLAGS.mysql-client
BUILDLINK_LDFLAGS.mysql-client= \
	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql			\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib/mysql

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql-client-buildlink

mysql-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
