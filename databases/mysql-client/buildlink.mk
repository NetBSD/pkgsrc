# $NetBSD: buildlink.mk,v 1.1 2001/11/02 02:57:28 jlam Exp $
#
# This Makefile fragment is included by packages that use mysql-client.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.mysql-client to the dependency pattern
#     for the version of mysql-client desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(MYSQL_CLIENT_BUILDLINK_MK)
MYSQL_CLIENT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.22
DEPENDS+=	${BUILDLINK_DEPENDS.mysql-client}:../../databases/mysql-client

EVAL_PREFIX+=		BUILDLINK_PREFIX.mysql-client=mysql-client
BUILDLINK_PREFIX.mysql-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql-client=		include/mysql/*.h
BUILDLINK_FILES.mysql-client+=		lib/mysql/libmysqlclient.*

.include "../../devel/zlib/buildlink.mk"

BUILDLINK_TARGETS.mysql-client=		mysql-client-buildlink
BUILDLINK_TARGETS.mysql-client+=	mysql-client-buildlink-config-wrapper
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.mysql-client}

BUILDLINK_CONFIG.mysql-client=	\
	${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
BUILDLINK_CONFIG_WRAPPER.mysql-client=	\
	${BUILDLINK_DIR}/bin/mysql_config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.mysql-client}|${BUILDLINK_CONFIG.mysql-client}|g"

.if defined(USE_CONFIG_WRAPPER)
MYSQL_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.mysql-client}
CONFIGURE_ENV+=		MYSQL_CONFIG="${MYSQL_CONFIG}"
MAKE_ENV+=		MYSQL_CONFIG="${MYSQL_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.mysql-client}
mysql-client-buildlink: _BUILDLINK_USE
mysql-client-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# MYSQL_CLIENT_BUILDLINK_MK
