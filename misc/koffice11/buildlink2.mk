# $NetBSD: buildlink2.mk,v 1.2 2003/05/02 11:55:56 wiz Exp $
#
# This Makefile fragment is included by packages that use koffice.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(KOFFICE_BUILDLINK2_MK)
KOFFICE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			koffice
BUILDLINK_DEPENDS.koffice?=		koffice>=1.1.1nb2
BUILDLINK_PKGSRCDIR.koffice?=		../../misc/koffice11

EVAL_PREFIX+=	BUILDLINK_PREFIX.koffice=koffice
BUILDLINK_PREFIX.koffice_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.koffice+=	include/KDChartData.h
BUILDLINK_FILES.koffice+=	include/KDChartTable.h
BUILDLINK_FILES.koffice+=	include/KoApplicationIface.h
BUILDLINK_FILES.koffice+=	include/KoDocumentIface.h
BUILDLINK_FILES.koffice+=	include/KoMainWindowIface.h
BUILDLINK_FILES.koffice+=	include/KoViewIface.h
BUILDLINK_FILES.koffice+=	include/handler.h
BUILDLINK_FILES.koffice+=	include/kcoloractions.h
BUILDLINK_FILES.koffice+=	include/kformulacontainer.h
BUILDLINK_FILES.koffice+=	include/kformuladocument.h
BUILDLINK_FILES.koffice+=	include/kformulaview.h
BUILDLINK_FILES.koffice+=	include/koApplication.h
BUILDLINK_FILES.koffice+=	include/koChart.h
BUILDLINK_FILES.koffice+=	include/koChild.h
BUILDLINK_FILES.koffice+=	include/koClipart.h
BUILDLINK_FILES.koffice+=	include/koClipartCollection.h
BUILDLINK_FILES.koffice+=	include/koDataTool.h
BUILDLINK_FILES.koffice+=	include/koDocument.h
BUILDLINK_FILES.koffice+=	include/koDocumentChild.h
BUILDLINK_FILES.koffice+=	include/koDocumentInfo.h
BUILDLINK_FILES.koffice+=	include/koDocumentInfoDlg.h
BUILDLINK_FILES.koffice+=	include/koFactory.h
BUILDLINK_FILES.koffice+=	include/koFilter.h
BUILDLINK_FILES.koffice+=	include/koFilterManager.h
BUILDLINK_FILES.koffice+=	include/koFind.h
BUILDLINK_FILES.koffice+=	include/koFrame.h
BUILDLINK_FILES.koffice+=	include/koGlobal.h
BUILDLINK_FILES.koffice+=	include/koImage.h
BUILDLINK_FILES.koffice+=	include/koImageCollection.h
BUILDLINK_FILES.koffice+=	include/koKoolBar.h
BUILDLINK_FILES.koffice+=	include/koMainWindow.h
BUILDLINK_FILES.koffice+=	include/koPageLayoutDia.h
BUILDLINK_FILES.koffice+=	include/koPartSelectAction.h
BUILDLINK_FILES.koffice+=	include/koPartSelectDia.h
BUILDLINK_FILES.koffice+=	include/koPrintPreview.h
BUILDLINK_FILES.koffice+=	include/koQueryTrader.h
BUILDLINK_FILES.koffice+=	include/koReplace.h
BUILDLINK_FILES.koffice+=	include/koRuler.h
BUILDLINK_FILES.koffice+=	include/koStore.h
BUILDLINK_FILES.koffice+=	include/koStoreDevice.h
BUILDLINK_FILES.koffice+=	include/koTabChooser.h
BUILDLINK_FILES.koffice+=	include/koTemplateChooseDia.h
BUILDLINK_FILES.koffice+=	include/koTemplateCreateDia.h
BUILDLINK_FILES.koffice+=	include/koTemplates.h
BUILDLINK_FILES.koffice+=	include/koToolBox.h
BUILDLINK_FILES.koffice+=	include/koView.h
BUILDLINK_FILES.koffice+=	include/koprinter.h
BUILDLINK_FILES.koffice+=	include/tkaction.h
BUILDLINK_FILES.koffice+=	include/tkcoloractions.h
BUILDLINK_FILES.koffice+=	include/tkcombobox.h
BUILDLINK_FILES.koffice+=	include/tktoolbarbutton.h
BUILDLINK_FILES.koffice+=	lib/kchart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libabiwordexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libabiwordimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libapplixgraphicimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libapplixspreadimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libapplixwordimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libasciiexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libasciiimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libcsvexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libcsvimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libdocbookexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libgnumericexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libgnumericimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libhtmlexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libhtmlimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkchartpart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkformulapart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkiviopart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkofficescan.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkontourpart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkpresenterpart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkprkword.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkspelltool.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkspreadcalc.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkspreadhtmlexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkspreadpart.*
BUILDLINK_FILES.koffice+=	lib/kde2/libkwordpart.*
BUILDLINK_FILES.koffice+=	lib/kde2/liblatexexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libmsodimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libolefilter.*
BUILDLINK_FILES.koffice+=	lib/kde2/libqproimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/librtfexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libsvgexport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libsvgimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libwmfimport.*
BUILDLINK_FILES.koffice+=	lib/kde2/libxfigimport.*
BUILDLINK_FILES.koffice+=	lib/kformulamain.*
BUILDLINK_FILES.koffice+=	lib/kivio.*
BUILDLINK_FILES.koffice+=	lib/kontour.*
BUILDLINK_FILES.koffice+=	lib/koshell.*
BUILDLINK_FILES.koffice+=	lib/kpresenter.*
BUILDLINK_FILES.koffice+=	lib/kspread.*
BUILDLINK_FILES.koffice+=	lib/kword.*
BUILDLINK_FILES.koffice+=	lib/libkdchart.*
BUILDLINK_FILES.koffice+=	lib/libkformula.*
BUILDLINK_FILES.koffice+=	lib/libkivioconnectortool.*
BUILDLINK_FILES.koffice+=	lib/libkivioselecttool.*
BUILDLINK_FILES.koffice+=	lib/libkiviotexttool.*
BUILDLINK_FILES.koffice+=	lib/libkiviozoomtool.*
BUILDLINK_FILES.koffice+=	lib/libkochart.*
BUILDLINK_FILES.koffice+=	lib/libkodocinfopropspage.*
BUILDLINK_FILES.koffice+=	lib/libkofficecore.*
BUILDLINK_FILES.koffice+=	lib/libkofficeui.*
BUILDLINK_FILES.koffice+=	lib/libkoscript.*
BUILDLINK_FILES.koffice+=	lib/libkstore.*
BUILDLINK_FILES.koffice+=	lib/libkugarpart.*
BUILDLINK_FILES.koffice+=	lib/libkwmf.*

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

BUILDLINK_TARGETS+=	koffice-buildlink

koffice-buildlink: _BUILDLINK_USE

.endif	# KOFFICE_BUILDLINK2_MK
