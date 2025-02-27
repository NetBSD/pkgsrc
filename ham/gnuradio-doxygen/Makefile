# $NetBSD: Makefile,v 1.95 2025/02/27 13:49:53 adam Exp $

PKGNAME=	gnuradio-doxygen-${VERSION}
COMMENT=	Doxygen documentation of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

TOOL_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
TOOL_DEPENDS+=	doxygen>=1.9.5:../../devel/doxygen
TOOL_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TOOL_DEPENDS+=	tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar
TOOL_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TOOL_DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
TOOL_DEPENDS+=	web2c-[0-9]*:../../print/web2c

CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOXYGEN=ON

# Doxygen output is never reproducible.
PLIST_SRC=	${WRKDIR}/PLIST.STATIC

post-install: doxygen-plist
.PHONY: doxygen-plist
doxygen-plist:
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/gnuradio-${PKGVERSION_NOREV}/html -type f -print > ${WRKDIR}/PLIST.STATIC
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/gnuradio-${PKGVERSION_NOREV}/xml -type f -print >> ${WRKDIR}/PLIST.STATIC

.include "../../mk/bsd.pkg.mk"
