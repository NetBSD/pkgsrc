# $NetBSD: buildlink2.mk,v 1.10 2004/02/04 14:42:23 markd Exp $
#
# This Makefile fragment is included by packages that use kdenetwork.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KDENETWORK_BUILDLINK2_MK)
KDENETWORK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdenetwork
BUILDLINK_DEPENDS.kdenetwork?=		kdenetwork>=3.2.0
BUILDLINK_PKGSRCDIR.kdenetwork?=		../../net/kdenetwork3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdenetwork=kdenetwork
BUILDLINK_PREFIX.kdenetwork_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdenetwork+=	include/rss/*.h
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_accountconfig.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_appearanceconfig.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_autoreplace.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_behaviorconfig.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_cryptography.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_highlight.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_history.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_msn.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_nowlistening.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_texteffect.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_translator.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_kopete_webpresence.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_krfb.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_ktalkd.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kcm_lanbrowser.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kded_kinetd.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kdict_panelapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/khtml_kget.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kio_lan.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/knewsticker_panelapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_aim.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_autoreplace.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_chatwindow.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_connectionstatus.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_contactnotes.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_cryptography.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_highlight.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_history.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_icq.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_irc.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_jabber.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_msn.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_nowlistening.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_sms.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_texteffect.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_translator.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_webpresence.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kopete_yahoo.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kpf_panelapplet.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/kpfpropertiesdialog.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/ksirc.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkntsrcfilepropsdlg.*
BUILDLINK_FILES.kdenetwork+=	lib/kde3/libkrichtexteditpart.*
BUILDLINK_FILES.kdenetwork+=	lib/libkdeinit_ksirc.*
BUILDLINK_FILES.kdenetwork+=	lib/libkopete.*
BUILDLINK_FILES.kdenetwork+=	lib/libkopete_msn_shared.*
BUILDLINK_FILES.kdenetwork+=	lib/libkopete_oscar.*
BUILDLINK_FILES.kdenetwork+=	lib/librss.*

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdenetwork-buildlink

kdenetwork-buildlink: _BUILDLINK_USE

.endif	# KDENETWORK_BUILDLINK2_MK
