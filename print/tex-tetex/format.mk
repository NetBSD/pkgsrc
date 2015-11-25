# $NetBSD: format.mk,v 1.2 2015/11/25 12:53:09 jperkin Exp $
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

DEPENDS+=		tex-tetex>=3.0.27774:../../print/tex-tetex

FILES_SUBST+=		FMTUTIL_SYS=${LOCALBASE}/bin/fmtutil-sys
FILES_SUBST+=		FORMATS=${TEX_FORMATS:Q}
FILES_SUBST+=		PRINTF=${PRINTF:Q}
INSTALL_TEMPLATES+=	../../print/tex-tetex/files/format-install.tmpl
DEINSTALL_TEMPLATES+=	../../print/tex-tetex/files/format-deinstall.tmpl

.endif	# TEX_FORMAT_MK
