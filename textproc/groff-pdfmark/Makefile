# $NetBSD: Makefile,v 1.1 2026/11/14 07:36:01 wiz Exp $

DISTNAME=	groff-pdfmark-20261029.1
PKGNAME=	groff-pdfmark-26.10
CATEGORIES=	textproc
MASTER_SITES=	https://download.savannah.gnu.org/releases/groff-pdfmark/
EXTRACT_SUFX=	-src.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/groff-pdfmark/
COMMENT=	PDF publishing macros and pdfroff driver for GNU troff
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/groff-pdfmark-26.10

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake sed

# Upstream's Makefile is mostly for release tarballs.
# We only need it to generate a proper pdfroff script.
BUILD_TARGET=	pdfroff-posix

# Runtime requirements
DEPENDS+=	groff-[0-9]*:../../textproc/groff
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript

# Macro packages to site-tmac only
TMAC_FILES=	pdfmark.tmac spdf.tmac omit.tmac opmode.tmac \
		sanitize.tmac pdfroff.tmac strcase.tmac newpage.tmac \
		float.tmac redirect.tmac appendix.tmac anpdf.tmac \
		toc-base.tmac toc-class.tmac spdf-toc.tmac fdl-setup.tmac

MAN1=	pdfroff.1
MAN7=	pdfroff.7 groff_pdfmark.7 groff_pdfhref.7 groff_pdfnote.7 \
	groff_mspdf.7 groff_omit.7 groff_opmode.7 groff_sanitize.7 \
	groff_toc.7

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1 ${PKGMANDIR}/man7 \
			share/groff/site-tmac \
			share/examples/groff-pdfmark \
			share/examples/groff-pdfmark/artwork \
			share/doc/groff-pdfmark

# Set a default GROFF_BIN_PATH to use pkgsrc groff, but make it so
# that users can still override the GROFF_BIN_PATH or GROFF_BIN_DIR
# variable at runtime.

SUBST_CLASSES+=		groffbin
SUBST_STAGE.groffbin=	post-build
SUBST_FILES.groffbin=	${BUILD_TARGET}

# Place default groff path expression before the
# first non-comment line in "pdfroff"

SUBST_FILTER_CMD.groffbin= \
	${AWK} '!inserted && /^[^\#]/ \
	{ \
	print "\# Use the groff installed in ${PREFIX} when GROFF_BIN_PATH is not set."; \
	print "\# Users may still override with GROFF_BIN_DIR or GROFF_BIN_PATH."; \
	print "\n  : $${GROFF_BIN_PATH:=${PREFIX}/bin}\n"; \
	inserted=1; \
	} \
	{ print }'

# Build only the POSIX pdfroff script
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_TARGET}
.for f in ${MAN1} ${MAN7}
	${SED} \
	    -e 's|@MAN1EXT@|1|g' \
	    -e 's|@MAN7EXT@|7|g' \
	    -e 's|@VERSION@|${PKGVERSION}|g' \
	    -e 's|@MDATE@|${PKGVERSION}|g' \
	    -e 's|@SITE_TMACDIR@|${PREFIX}/share/groff/site-tmac|g' \
	    -e 's|@PDFDOCDIR@|${PREFIX}/share/doc/groff-pdfmark|g' \
	    -e 's|@AUTHOR_MT_ADDRESS@|keith.d.marshall@ntlworld.com|g' \
	    -e 's|@PROJECT_HOSTING_SITE@|https://savannah.nongnu.org/projects/groff-pdfmark/|g' \
	    -e '/@IMPORT_LOCAL_FALLBACK_MACROS@/d' \
	    -e '/@ENUMERATE_MR_REFERENCES@/d' \
	    ${WRKSRC}/man/${f}.man > ${WRKDIR}/${f}
.endfor

do-install:
	# Generated driver (upstream builds it as pdfroff-posix)
	${INSTALL_SCRIPT} ${WRKSRC}/pdfroff-posix \
		${DESTDIR}${PREFIX}/bin/pdfroff

# Macros
.for f in ${TMAC_FILES}
	${INSTALL_DATA} ${WRKSRC}/tmac/${f} \
		${DESTDIR}${PREFIX}/share/groff/site-tmac/
.endfor

# Man pages
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}
.endfor
.for f in ${MAN7}
	${INSTALL_MAN} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/${f}
.endfor

	# Example sources so users can rebuild the reference document
	${INSTALL_DATA} ${WRKSRC}/pdfmark.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/cover.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/cover-info.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/fdl-typesetting.ms \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/artwork/gnu.eps \
		${DESTDIR}${PREFIX}/share/examples/groff-pdfmark/artwork/

	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${DESTDIR}${PREFIX}/share/doc/groff-pdfmark/
	${INSTALL_DATA} ${WRKSRC}/gpl-v3.0.txt \
		${DESTDIR}${PREFIX}/share/doc/groff-pdfmark/

.include "../../mk/bsd.pkg.mk"
