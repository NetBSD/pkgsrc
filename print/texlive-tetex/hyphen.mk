# $NetBSD: hyphen.mk,v 1.3 2010/11/08 00:25:51 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX hyphenation pattens.  It updates format files at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_HYPHEN_DAT - A list of hyphenation entries for language.dat.
#    TEX_HYPHEN_DEF - A list of hyphenation entries for language.def.
#    TEX_HYPHEN_LUA - A list of hyphenation entries for language.dat.lua.
#

.if !defined(TEX_HYPHEN_MK)
TEX_HYPHEN_MK=		# defined

DEPENDS+=		texlive-tetex>=2010:../../print/texlive-tetex
DEPENDS+=		tex-hyphen-base>=2010nb1:../../print/tex-hyphen-base

EVAL_PREFIX+=		TETEX_PREFIX=texlive-tetex
FILES_SUBST+=		FMTUTIL_SYS=${TETEX_PREFIX:Q}/bin/fmtutil-sys
FILES_SUBST+=		HYPHEN_DAT=${TEX_HYPHEN_DAT:Q}
FILES_SUBST+=		HYPHEN_DEF=${TEX_HYPHEN_DEF:Q}
FILES_SUBST+=		HYPHEN_LUA=${TEX_HYPHEN_LUA:Q}
INSTALL_TEMPLATES+=	../../print/texlive-tetex/files/hyphen-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/texlive-tetex/files/hyphen-deinstall.tmpl

.endif	# TEX_HYPHEN_MK
