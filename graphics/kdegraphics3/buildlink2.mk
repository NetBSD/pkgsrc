# $NetBSD: buildlink2.mk,v 1.12 2004/02/05 01:32:47 markd Exp $
#
# This Makefile fragment is included by packages that use kdegraphics.
#

.if !defined(KDEGRAPHICS_BUILDLINK2_MK)
KDEGRAPHICS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			kdegraphics
BUILDLINK_DEPENDS.kdegraphics?=		kdegraphics>=3.2.0
BUILDLINK_PKGSRCDIR.kdegraphics?=		../../graphics/kdegraphics3

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdegraphics=kdegraphics
BUILDLINK_PREFIX.kdegraphics_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.kdegraphics+=	include/devselector.h
BUILDLINK_FILES.kdegraphics+=	include/dispgamma.h
BUILDLINK_FILES.kdegraphics+=	include/gammadialog.h
BUILDLINK_FILES.kdegraphics+=	include/img_canvas.h
BUILDLINK_FILES.kdegraphics+=	include/imgscaledialog.h
BUILDLINK_FILES.kdegraphics+=	include/kgammatable.h
BUILDLINK_FILES.kdegraphics+=	include/kmultipageInterface.h
BUILDLINK_FILES.kdegraphics+=	include/kscandevice.h
BUILDLINK_FILES.kdegraphics+=	include/kscanoption.h
BUILDLINK_FILES.kdegraphics+=	include/kscanoptset.h
BUILDLINK_FILES.kdegraphics+=	include/kscanslider.h
BUILDLINK_FILES.kdegraphics+=	include/massscandialog.h
BUILDLINK_FILES.kdegraphics+=	include/previewer.h
BUILDLINK_FILES.kdegraphics+=	include/scanparams.h
BUILDLINK_FILES.kdegraphics+=	include/scansourcedialog.h
BUILDLINK_FILES.kdegraphics+=	include/sizeindicator.h
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kgamma.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kmrml.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kviewcanvasconfig.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kviewgeneralconfig.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kviewpluginsconfig.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kviewpresenterconfig.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kcm_kviewviewerpluginsconfig.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kded_daemonwatcher.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kdvipart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfaxpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_bmp.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_dvi.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_ico.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_jpeg.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_pcx.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_pdf.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_png.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_pnm.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_ps.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_tga.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_tiff.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kfile_xbm.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kio_mrml.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kuickshow.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kview.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kview_browserplugin.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kview_effectsplugin.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kview_presenterplugin.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kview_scannerplugin.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/kviewerpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkghostviewpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkmrmlpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkpdfpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkpovmodelerpart.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkviewcanvas.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/libkviewviewer.*
BUILDLINK_FILES.kdegraphics+=	lib/kde3/mrmlsearch.*
BUILDLINK_FILES.kdegraphics+=	lib/libkdeinit_kuickshow.*
BUILDLINK_FILES.kdegraphics+=	lib/libkdeinit_kview.*
BUILDLINK_FILES.kdegraphics+=	lib/libkdeinit_mrmlsearch.*
BUILDLINK_FILES.kdegraphics+=	lib/libkimageviewer.*
BUILDLINK_FILES.kdegraphics+=	lib/libkmultipage.*
BUILDLINK_FILES.kdegraphics+=	lib/libkpovmodeler.*
BUILDLINK_FILES.kdegraphics+=	lib/libkscan.*

.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/sane-backends/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"

BUILDLINK_TARGETS+=	kdegraphics-buildlink

kdegraphics-buildlink: _BUILDLINK_USE

.endif	# KDEGRAPHICS_BUILDLINK2_MK
