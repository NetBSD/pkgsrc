# $NetBSD: buildlink2.mk,v 1.9 2003/12/08 14:41:41 wiz Exp $
#
# This Makefile fragment is included by packages that use kdenetwork.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDENETWORK_BUILDLINK2_MK)
KDENETWORK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdenetwork
BUILDLINK_DEPENDS.kdenetwork?=		kdenetwork>=3.1.4nb1
BUILDLINK_PKGSRCDIR.kdenetwork?=		../../net/kdenetwork3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdenetwork=kdenetwork
BUILDLINK_PREFIX.kdenetwork_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdenetwork+=	include/kmailIface.h
BUILDLINK_FILES.kdenetwork+=	include/mimelib/*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kdictapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/knewsticker_applet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kpfapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kpfpropertiesdialogplugin.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkcm_kcmkxmlrpcd.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkcm_ktalkd.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkcm_lanbrowser.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkcm_newsticker.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkcm_xmlrpcd.*
BUILDLINK_FILES.kdenetwork+=	lib/kio_lan.*
BUILDLINK_FILES.kdenetwork+=	lib/ksirc.*
BUILDLINK_FILES.kdenetwork+=	lib/kxmlrpcd.*
BUILDLINK_FILES.kdenetwork+=	lib/libkdenetwork.*
BUILDLINK_FILES.kdenetwork+=	lib/libkntsrcfilepropsdlg.*
BUILDLINK_FILES.kdenetwork+=	lib/libksirc_main.*
BUILDLINK_FILES.kdenetwork+=	lib/libkxmlrpcd_main.*
BUILDLINK_FILES.kdenetwork+=	lib/libmimelib.*

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdenetwork-buildlink

kdenetwork-buildlink: _BUILDLINK_USE

.endif	# KDENETWORK_BUILDLINK2_MK
