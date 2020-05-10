# $NetBSD: map.mk,v 1.1 2020/05/10 03:56:44 markd Exp $
#
# This Makefile fragment is intended to be included by packages that
# install font maps for TeX.  It updates font map entries in updmap.cfg
# at (de)installation time.
#
# The following variables can be defined:
#
#    TEX_MAP_FILES - A list of map files.
#
#    TEX_MIXEDMAP_FILES - A list of mixed map files.
#
#    TEX_KANJIMAP_FILES - A list of kanji map files.
#

.if !defined(TEX_MAP_MK)
TEX_MAP_MK=		# defined

DEPENDS+=		tex-texlive-scripts>=2020:../../print/tex-texlive-scripts

FILES_SUBST+=		UPDMAP_SYS=${LOCALBASE}/bin/updmap-sys
FILES_SUBST+=		MAP_FILES=${TEX_MAP_FILES:Q}
FILES_SUBST+=		MIXEDMAP_FILES=${TEX_MIXEDMAP_FILES:Q}
FILES_SUBST+=		KANJIMAP_FILES=${TEX_KANJIMAP_FILES:Q}
INSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/map-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/map-deinstall.tmpl

.endif	# TEX_MAP_MK
