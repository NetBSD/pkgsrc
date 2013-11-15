# $NetBSD: hyphen.mk,v 1.1 2013/11/15 06:08:51 minskim Exp $
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

DEPENDS+=		tex-hyphen-base>=2010nb1:../../print/tex-hyphen-base
DEPENDS+=		tex-tetex>=3.0.27774nb1:../../print/tex-tetex

EVAL_PREFIX+=		TETEX_PREFIX=tex-tetex
FILES_SUBST+=		FMTUTIL_SYS=${TETEX_PREFIX:Q}/bin/fmtutil-sys
FILES_SUBST+=		HYPHEN_DAT=${TEX_HYPHEN_DAT:Q}
FILES_SUBST+=		HYPHEN_DEF=${TEX_HYPHEN_DEF:Q}
FILES_SUBST+=		HYPHEN_LUA=${TEX_HYPHEN_LUA:Q}
INSTALL_TEMPLATES+=	../../print/tex-tetex/files/hyphen-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/tex-tetex/files/hyphen-deinstall.tmpl

.endif	# TEX_HYPHEN_MK
