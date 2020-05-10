# $NetBSD: format.mk,v 1.1 2020/05/10 03:56:44 markd Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX format files.  It creates format files at
# (de)installation time.
#
# The following variable can be defined:
#
#    TEX_FORMATS - A list of parameters to build formats
#

.if !defined(TEX_FORMAT_MK)
TEX_FORMAT_MK=		# defined

DEPENDS+=		tex-texlive-scripts>=2020:../../print/tex-texlive-scripts

FILES_SUBST+=		FMTUTIL_SYS=${LOCALBASE}/bin/fmtutil-sys
FILES_SUBST+=		FORMATS=${TEX_FORMATS:Q}
FILES_SUBST+=		PRINTF=${PRINTF:Q}
INSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/format-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/tex-texlive-scripts/files/format-deinstall.tmpl

.endif	# TEX_FORMAT_MK
