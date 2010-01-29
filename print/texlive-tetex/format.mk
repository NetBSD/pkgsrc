# $NetBSD: format.mk,v 1.5 2010/01/29 19:59:47 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX format files.  It creates format files at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_FORMATS - A list of parameters to build formats
#
#    TEX_FORMAT_NAMES (for TeX Live 2008 only) - A list of format names.
#

.if !defined(TEX_FORMAT_MK)
TEX_FORMAT_MK=		# defined

DEPENDS+=		texlive-tetex>=2008:../../print/texlive-tetex

EVAL_PREFIX+=		TETEX_PREFIX=texlive-tetex
FILES_SUBST+=		FMTUTIL_SYS=${TETEX_PREFIX:Q}/bin/fmtutil-sys
FILES_SUBST+=		FORMAT_NAMES=${TEX_FORMAT_NAMES:Q}
FILES_SUBST+=		FORMATS=${TEX_FORMATS:Q}
FILES_SUBST+=		PRINTF=${PRINTF:Q}
INSTALL_TEMPLATES+=	../../print/texlive-tetex/files/format-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/texlive-tetex/files/format-deinstall.tmpl

.endif	# TEX_FORMAT_MK
