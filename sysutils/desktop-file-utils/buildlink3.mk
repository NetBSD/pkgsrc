# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:23 joerg Exp $

BUILDLINK_TREE+=	desktop-file-utils

.if !defined(DESKTOP_FILE_UTILS_BUILDLINK3_MK)
DESKTOP_FILE_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.desktop-file-utils+=	desktop-file-utils>=0.8
BUILDLINK_ABI_DEPENDS.desktop-file-utils+=	desktop-file-utils>=0.10nb1
BUILDLINK_PKGSRCDIR.desktop-file-utils?=../../sysutils/desktop-file-utils

BUILDLINK_TARGETS+=	desktop-file-utils-buildlink-fake

_DFU_FAKE_UPDATEDB=	${BUILDLINK_DIR}/bin/update-desktop-database

desktop-file-utils-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_DFU_FAKE_UPDATEDB} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_DFU_FAKE_UPDATEDB}";	\
		${MKDIR} ${_DFU_FAKE_UPDATEDB:H};			\
		${ECHO} "#!/bin/sh" > ${_DFU_FAKE_UPDATEDB};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for update-desktop-database' \$$*" >> ${_DFU_FAKE_UPDATEDB};		\
		${CHMOD} +x ${_DFU_FAKE_UPDATEDB};			\
	fi
.endif # DESKTOP_FILE_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-desktop-file-utils
