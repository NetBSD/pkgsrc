# $NetBSD: format.mk,v 1.1.1.1 2009/01/26 21:04:33 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX format files.  It creates format files at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_FORMAT_NAMES - A list of format names.
#

.if !defined(TEX_FORMAT_MK)
TEX_FORMAT_MK=		# defined

DEPENDS+=		texlive-tetex>=2008:../../print/texlive-tetex

EVAL_PREFIX+=		TETEX_PREFIX=texlive-tetex
FILES_SUBST+=		FMTUTIL_SYS=${TETEX_PREFIX:Q}/bin/fmtutil-sys
FILES_SUBST+=		FORMAT_NAMES=${TEX_FORMAT_NAMES:Q}
INSTALL_TEMPLATES+=	../../print/texlive-tetex/files/format-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/texlive-tetex/files/format-deinstall.tmpl

.endif	# TEX_FORMAT_MK
