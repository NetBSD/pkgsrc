# $NetBSD: texmf.mk,v 1.7 2013/11/15 06:08:51 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX packages.  It rebuilds the ls-R databases at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_TEXMF_DIRS - A list of texmf directories that need to update ls-R.
#                     Default: ${PREFIX}/share/texmf-dist
#
#    TEX_CONFIG_NAMES - A list of config fragments to add to texmf.cnf.
#
#    TEX_KANJIMAP_FILES
#	See ../../print/texlive-tetex/map.mk.
#
#    TEX_MAP_FILES
#	See ../../print/texlive-tetex/map.mk.
#
#    TEX_MIXEDMAP_FILES
#	See ../../print/texlive-tetex/map.mk.
#

.if !defined(TEX_TEXMF_MK)
TEX_TEXMF_MK=		# defined

DEPENDS+=		kpathsea>=3.5.7:../../print/kpathsea

TEX_TEXMF_DIRS?=	${PREFIX}/share/texmf-dist
EVAL_PREFIX+=		KPATHSEA_PREFIX=kpathsea
FILES_SUBST+=		MKTEXLSR=${KPATHSEA_PREFIX:Q}/bin/mktexlsr
FILES_SUBST+=		TEXMF_DIRS=${TEX_TEXMF_DIRS:Q}
.if !empty(TEX_TEXMF_DIRS)
INSTALL_TEMPLATES+=	../../print/kpathsea/files/texmf-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/kpathsea/files/texmf-deinstall.tmpl
.endif

.  if !empty(TEX_CONFIG_NAMES)
FILES_SUBST+=		CONFIG_NAMES=${TEX_CONFIG_NAMES:Q}
INSTALL_TEMPLATES+=	../../print/kpathsea/files/config-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/kpathsea/files/config-deinstall.tmpl
.  endif

.if !empty(TEX_FORMATS)
.  include "../../print/tex-tetex/format.mk"
.endif
.if !empty(TEX_HYPHEN_DAT) || !empty(TEX_HYPHEN_DEF)
.  include "../../print/tex-tetex/hyphen.mk"
.endif
.if !empty(TEX_KANJIMAP_FILES) || !empty(TEX_MAP_FILES) \
	|| !empty(TEX_MIXEDMAP_FILES)
.  include "../../print/tex-tetex/map.mk"
.endif

.endif	# TEX_TEXMF_MK
