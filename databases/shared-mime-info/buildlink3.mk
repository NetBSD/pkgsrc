# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:05 rillig Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
SHARED_MIME_INFO_BUILDLINK3_MK:=	${SHARED_MIME_INFO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	shared-mime-info
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nshared-mime-info}
BUILDLINK_PACKAGES+=	shared-mime-info

.if !empty(SHARED_MIME_INFO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.shared-mime-info+=	shared-mime-info>=0.15
BUILDLINK_ABI_DEPENDS.shared-mime-info?=	shared-mime-info>=0.16nb2
BUILDLINK_PKGSRCDIR.shared-mime-info?=	../../databases/shared-mime-info
.endif	# SHARED_MIME_INFO_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.if !empty(SHARED_MIME_INFO_BUILDLINK3_MK:M+)
BUILDLINK_TARGETS+=	shared-mime-info-buildlink-fake

_SMI_FAKE_UPDATEDB=	${BUILDLINK_DIR}/bin/update-mime-database

shared-mime-info-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_SMI_FAKE_UPDATEDB} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_SMI_FAKE_UPDATEDB}";	\
		${MKDIR} ${_SMI_FAKE_UPDATEDB:H};			\
		${ECHO} "#!/bin/sh" > ${_SMI_FAKE_UPDATEDB};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for update-mime-database' \$$*" >> ${_SMI_FAKE_UPDATEDB};		\
		${CHMOD} +x ${_SMI_FAKE_UPDATEDB};			\
	fi
.endif	# SHARED_MIME_INFO_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
