# $NetBSD: hyphen.mk,v 1.1 2020/05/10 03:56:44 markd Exp $
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
DEPENDS+=		tex-texlive-scripts>=2020:../../print/tex-texlive-scripts

FILES_SUBST+=		FMTUTIL_SYS=${LOCALBASE}/bin/fmtutil-sys
FILES_SUBST+=		HYPHEN_DAT=${TEX_HYPHEN_DAT:Q}
FILES_SUBST+=		HYPHEN_DEF=${TEX_HYPHEN_DEF:Q}
FILES_SUBST+=		HYPHEN_LUA=${TEX_HYPHEN_LUA:Q}
INSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/hyphen-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/hyphen-deinstall.tmpl

.endif	# TEX_HYPHEN_MK
