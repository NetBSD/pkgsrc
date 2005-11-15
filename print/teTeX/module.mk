# $NetBSD: module.mk,v 1.2 2005/11/15 07:13:19 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that
# install TeX packages.  It takes care of rebuilding the ls-R database
# at (de)installation time.
#
# The following variable can be defined:
#
#    TEXMFDIRS - A list of TEXMF directories that need to update ls-R.
#                Default: ${PKG_LOCALTEXMFPREFIX}
#
#    TEXFONTMAPS - A list of font map files
#

.if !defined(TEX_PACKAGE_MK)
TEX_PACKAGE_MK=		# defined

TEXMFDIRS?=		${PKG_LOCALTEXMFPREFIX}
TEXFONTMAPS?=		# empty

USE_PKGINSTALL=		yes
FILES_SUBST+=		MKTEXLSR="${LOCALBASE}/bin/mktexlsr"
FILES_SUBST+=		TEXMFDIRS="${TEXMFDIRS}"
FILES_SUBST+=		UPDMAP_SYS="${LOCALBASE}/bin/updmap-sys"
FILES_SUBST+=		TEXFONTMAPS="${TEXFONTMAPS}"
INSTALL_EXTRA_TMPL+=	../../print/teTeX/files/texmf.tmpl
DEINSTALL_EXTRA_TMPL+=	../../print/teTeX/files/texmf.tmpl

PRINT_PLIST_AWK+=	/^(@dirrm )?${PKG_LOCALTEXMFPREFIX:S|${PREFIX}/||:S|/|\\/|g}(\/ls-R)?$$/ \
			{ next; }

.include "../../mk/tex.buildlink3.mk"

.endif			# TEX_PACKAGE_MK
