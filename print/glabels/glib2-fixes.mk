# $NetBSD: glib2-fixes.mk,v 1.1 2012/05/08 02:41:26 dholland Exp $

# Fix build with the latest glib2.

SUBST_CLASSES+=		glib2
SUBST_MESSAGE.glib2=	Fixing glib2 includes.
# For testing, post-patch is better. For production, pre-build decreases
# the chances of confusion and of bad interactions with patches.
#SUBST_STAGE.glib2=	post-patch
SUBST_STAGE.glib2=	pre-build

SUBST_FILES.glib2+=	libglabels/category.c
SUBST_FILES.glib2+=	libglabels/category.h
SUBST_FILES.glib2+=	libglabels/db.c
SUBST_FILES.glib2+=	libglabels/db.h
SUBST_FILES.glib2+=	libglabels/libglabels-private.h
SUBST_FILES.glib2+=	libglabels/paper.c
SUBST_FILES.glib2+=	libglabels/paper.h
SUBST_FILES.glib2+=	libglabels/template.c
SUBST_FILES.glib2+=	libglabels/template.h
SUBST_FILES.glib2+=	libglabels/xml-category.c
SUBST_FILES.glib2+=	libglabels/xml-category.h
SUBST_FILES.glib2+=	libglabels/xml-paper.c
SUBST_FILES.glib2+=	libglabels/xml-paper.h
SUBST_FILES.glib2+=	libglabels/xml-template.c
SUBST_FILES.glib2+=	libglabels/xml.c
SUBST_FILES.glib2+=	libglabels/xml.h
SUBST_FILES.glib2+=	src/base64.c
SUBST_FILES.glib2+=	src/base64.h
SUBST_FILES.glib2+=	src/bc-gnubarcode.c
SUBST_FILES.glib2+=	src/bc-iec16022.c
SUBST_FILES.glib2+=	src/bc-postnet.c
SUBST_FILES.glib2+=	src/bc.c
SUBST_FILES.glib2+=	src/bc.h
SUBST_FILES.glib2+=	src/critical-error-handler.c
SUBST_FILES.glib2+=	src/critical-error-handler.h
SUBST_FILES.glib2+=	src/debug.c
SUBST_FILES.glib2+=	src/debug.h
SUBST_FILES.glib2+=	src/label-barcode.c
SUBST_FILES.glib2+=	src/label-box.c
SUBST_FILES.glib2+=	src/label-ellipse.c
SUBST_FILES.glib2+=	src/label-image.c
SUBST_FILES.glib2+=	src/label-line.c
SUBST_FILES.glib2+=	src/label-object.c
SUBST_FILES.glib2+=	src/label-text.c
SUBST_FILES.glib2+=	src/mini-preview-pixbuf-cache.c
SUBST_FILES.glib2+=	src/pixbuf-cache.h
SUBST_FILES.glib2+=	src/stock.h
SUBST_FILES.glib2+=	src/text-node.h
SUBST_FILES.glib2+=	src/util.h
SUBST_FILES.glib2+=	src/view-barcode.c
SUBST_FILES.glib2+=	src/view-box.c
SUBST_FILES.glib2+=	src/view-ellipse.c
SUBST_FILES.glib2+=	src/view-image.c
SUBST_FILES.glib2+=	src/view-line.c
SUBST_FILES.glib2+=	src/view-text.c
SUBST_FILES.glib2+=	src/warning-handler.c
SUBST_FILES.glib2+=	src/warning-handler.h

SUBST_SED.glib2+=	-e '/\#include/s,<glib/gdir.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gfileutils.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/ghash.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/glist.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gmacros.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gmem.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gmessages.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gqsort.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gstrfuncs.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gstring.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gtypes.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gunicode.h>,<glib.h>,'
SUBST_SED.glib2+=	-e '/\#include/s,<glib/gutils.h>,<glib.h>,'
