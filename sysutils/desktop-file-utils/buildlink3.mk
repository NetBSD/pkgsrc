# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/09/21 17:03:54 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
DESKTOP_FILE_UTILS_BUILDLINK3_MK:=	${DESKTOP_FILE_UTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	desktop-file-utils
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndesktop-file-utils}
BUILDLINK_PACKAGES+=	desktop-file-utils

.if !empty(DESKTOP_FILE_UTILS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.desktop-file-utils+=	desktop-file-utils>=0.8
BUILDLINK_PKGSRCDIR.desktop-file-utils?=../../sysutils/desktop-file-utils
.endif	# DESKTOP_FILE_UTILS_BUILDLINK3_MK

.if !empty(DESKTOP_FILE_UTILS_BUILDLINK3_MK:M+)
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
.endif	# DESKTOP_FILE_UTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
