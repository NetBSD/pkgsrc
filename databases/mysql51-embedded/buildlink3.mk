# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/15 17:01:12 wiz Exp $

BUILDLINK_TREE+=	mysql-embedded

.if !defined(MYSQL_EMBEDDED_BUILDLINK3_MK)
MYSQL_EMBEDDED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-embedded+=	mysql-embedded>=5.1.36nb3
BUILDLINK_PKGSRCDIR.mysql-embedded?=	../../databases/mysql51-embedded

MYSQLD_PATH=		${BUILDLINK_PREFIX.mysql-embedded}/mysqld/lib/mysql
BUILDLINK_PASSTHRU_DIRS+=		${MYSQLD_PATH}
BUILDLINK_PASSTHRU_RPATHDIRS+=		${MYSQLD_PATH}
.endif # MYSQL_EMBEDDED_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-embedded
