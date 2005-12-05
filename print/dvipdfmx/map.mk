# $NetBSD: map.mk,v 1.3 2005/12/05 20:50:52 rillig Exp $
# This Makefile fragment is intended to be included by packages that
# install font maps used by dvipdfmx.  It takes care of adding and
# removing font map entires in dvipdfmx.cfg.
#
# The following variable can be defined:
#
#     DVIPDFMX_FONTMAPS - A list of font map files to be included in
#	dvipdfmx.cnf.
#

.if !defined(DVIPDFMX_MAP_MK)
DVIPDFMX_MAP_MK=	# defined

DVIPDFMX_FONTMAPS?=	# empty

.if empty(DISTNAME:Mdvipdfmx-[0-9]*)
DEPENDS+=		dvipdfmx>=0.0.0.20050627:../../print/dvipdfmx
.endif

USE_PKGINSTALL=		yes
FILES_SUBST+=		DVIPDFMX_FONTMAPS=${DVIPDFMX_FONTMAPS:Q}
FILES_SUBST+=		DVIPDFMX_CONFIG_DIR="${PKG_LOCALTEXMFPREFIX}/dvipdfm/config"
INSTALL_EXTRA_TMPL+=	../../print/dvipdfmx/files/map.tmpl
DEINSTALL_EXTRA_TMPL+=	../../print/dvipdfmx/files/map.tmpl

PRINT_PLIST_AWK+=	/^${PKG_LOCALTEXMFPREFIX:S|${PREFIX}/||:S|/|\\/|g}\/dvidpfm\/config\/dvipdfmx.cfg$$/ \
			{ next; }

.endif			# DVIPDFMX_MAP_MK
