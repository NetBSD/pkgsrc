# $NetBSD: buildlink3.mk,v 1.11 2009/05/16 07:22:02 rillig Exp $

BUILDLINK_TREE+=	shared-mime-info

.if !defined(SHARED_MIME_INFO_BUILDLINK3_MK)
SHARED_MIME_INFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.shared-mime-info+=	shared-mime-info>=0.15
BUILDLINK_ABI_DEPENDS.shared-mime-info+=	shared-mime-info>=0.16nb2
BUILDLINK_PKGSRCDIR.shared-mime-info?=	../../databases/shared-mime-info

BUILDLINK_TARGETS+=	shared-mime-info-buildlink-fake

_SMI_FAKE_UPDATEDB=	${BUILDLINK_DIR}/bin/update-mime-database

.PHONY: shared-mime-info-buildlink-fake
shared-mime-info-buildlink-fake:
	${RUN} \
	if [ ! -f ${_SMI_FAKE_UPDATEDB:Q} ]; then			\
		${ECHO_BUILDLINK_MSG} "Creating "${_SMI_FAKE_UPDATEDB:Q}; \
		${MKDIR} ${_SMI_FAKE_UPDATEDB:H};			\
		${ECHO} "#!/bin/sh" > ${_SMI_FAKE_UPDATEDB};		\
		${ECHO} 'if [ "$$1" = "-v" ]; then' ${BUILDLINK_PREFIX.shared-mime-info}/bin/update-mime-database "-v; fi" >> ${_SMI_FAKE_UPDATEDB};		\
		${ECHO} "echo '[pkgsrc] Doing nothing for update-mime-database' \$$*" >> ${_SMI_FAKE_UPDATEDB};		\
		${CHMOD} +x ${_SMI_FAKE_UPDATEDB};			\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # SHARED_MIME_INFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-shared-mime-info
