# $NetBSD: buildlink2.mk,v 1.9 2004/02/04 22:50:18 markd Exp $
#
# This Makefile fragment is included by packages that use kdepim.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(KDEPIM_BUILDLINK2_MK)
KDEPIM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdepim
BUILDLINK_DEPENDS.kdepim?=		kdepim>=3.2.0
BUILDLINK_PKGSRCDIR.kdepim?=		../../misc/kdepim3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdepim=kdepim
BUILDLINK_PREFIX.kdepim_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdepim+=	include/KDGanttView.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewEventItem.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewItem.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewSummaryItem.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewTaskItem.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewTaskLink.h
BUILDLINK_FILES.kdepim+=	include/KDGanttViewTaskLinkGroup.h
BUILDLINK_FILES.kdepim+=	include/KDXMLTools.h
BUILDLINK_FILES.kdepim+=	include/KNotesIface.h
BUILDLINK_FILES.kdepim+=	include/calendar/*
BUILDLINK_FILES.kdepim+=	include/kaddressbook/*
BUILDLINK_FILES.kdepim+=	include/kdepim/*
BUILDLINK_FILES.kdepim+=	include/kgantt/*
BUILDLINK_FILES.kdepim+=	include/kmailIface.h
BUILDLINK_FILES.kdepim+=	include/kmailicalIface.h
BUILDLINK_FILES.kdepim+=	include/kmailpartIface.h
BUILDLINK_FILES.kdepim+=	include/knewstuff/*
BUILDLINK_FILES.kdepim+=	include/kontact/*
BUILDLINK_FILES.kdepim+=	include/korganizer/*
BUILDLINK_FILES.kdepim+=	include/kpilot/*
BUILDLINK_FILES.kdepim+=	include/ksieve/*
BUILDLINK_FILES.kdepim+=	include/ktnef/*
BUILDLINK_FILES.kdepim+=	include/libkcal/*
BUILDLINK_FILES.kdepim+=	include/mimelib/*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_address.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_doc.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_knotes.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_popmail.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_sysinfo.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_time.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_todo.*
BUILDLINK_FILES.kdepim+=	lib/kde3/conduit_vcal.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kabc_imap.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcal_imap.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcal_kabc.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcal_local.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcal_localdir.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcal_remote.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcm_kabconfig.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcm_kabldapconfig.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcm_kontact.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kcm_korganizer.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kfile_vcf.*
BUILDLINK_FILES.kdepim+=	lib/kde3/kio_sieve.*
BUILDLINK_FILES.kdepim+=	lib/kde3/ldifvcardthumbnail.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_bookmark_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_cardview.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_csv_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_distributionlist.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_eudora_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_gnokii_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_iconview.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_kde2_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_ldif_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_location.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_merge.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_opera_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_pab_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_tableview.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddrbk_vcard_xxport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkaddressbookpart.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkmailpart.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libknodepart.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_kaddressbookplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_kmailplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_knodeplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_knotesplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_korganizerplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_summaryplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_todoplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkontact_weatherplugin.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_birthdays.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_datenums.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_exchange.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_hebrew.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_holidays.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_projectview.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorg_webexport.*
BUILDLINK_FILES.kdepim+=	lib/kde3/libkorganizerpart.*
BUILDLINK_FILES.kdepim+=	lib/libkabinterfaces.*
BUILDLINK_FILES.kdepim+=	lib/libkaddressbook.*
BUILDLINK_FILES.kdepim+=	lib/libkalarmd.*
BUILDLINK_FILES.kdepim+=	lib/libkcal.*
BUILDLINK_FILES.kdepim+=	lib/libkdenetwork.*
BUILDLINK_FILES.kdepim+=	lib/libkdepim.*
BUILDLINK_FILES.kdepim+=	lib/libkdgantt.*
BUILDLINK_FILES.kdepim+=	lib/libkgantt.*
BUILDLINK_FILES.kdepim+=	lib/libkmailprivate.*
BUILDLINK_FILES.kdepim+=	lib/libknewstuff.*
BUILDLINK_FILES.kdepim+=	lib/libkontact.*
BUILDLINK_FILES.kdepim+=	lib/libkorganizer.*
BUILDLINK_FILES.kdepim+=	lib/libkorganizer_eventviewer.*
BUILDLINK_FILES.kdepim+=	lib/libkpilot.*
BUILDLINK_FILES.kdepim+=	lib/libkpimexchange.*
BUILDLINK_FILES.kdepim+=	lib/libkpinterfaces.*
BUILDLINK_FILES.kdepim+=	lib/libksieve.*
BUILDLINK_FILES.kdepim+=	lib/libksync.*
BUILDLINK_FILES.kdepim+=	lib/libktnef.*
BUILDLINK_FILES.kdepim+=	lib/libmimelib.*

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdepim-buildlink

kdepim-buildlink: _BUILDLINK_USE

.endif	# KDEPIM_BUILDLINK2_MK
