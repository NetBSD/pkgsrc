# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:34 jlam Exp $
#
# This Makefile fragment is included by packages that use mysql-client.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mysql-client to the dependency pattern
#     for the version of mysql-client desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.22
DEPENDS+=	${BUILDLINK_DEPENDS.mysql-client}:../../databases/mysql-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=	include/mysql/*.h
BUILDLINK_FILES.mysql-client+=	lib/mysql/libmysqlclient.*

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql-client-buildlink

mysql-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
