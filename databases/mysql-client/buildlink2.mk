# $NetBSD: buildlink2.mk,v 1.4 2002/12/13 14:19:54 tron Exp $

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mysql-client
BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.49nb2
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mysql-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=	include/mysql/*.h
BUILDLINK_FILES.mysql-client+=	lib/mysql/libmysqlclient.*

BUILDLINK_LDFLAGS.mysql-client= \
	-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql			\
	-Wl,-R${BUILDLINK_PREFIX.mysql-client}/lib/mysql

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql-client-buildlink

mysql-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
