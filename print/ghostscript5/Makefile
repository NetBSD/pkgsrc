# $NetBSD: Makefile,v 1.53 2000/04/16 17:25:59 jlam Exp $

PKGNAME=	${DISTNAME}nb1
MASTER_SITES+=	http://www.ozemail.com.au/~geoffk/pdfencrypt/
DISTFILES+=	${GS_FONTS_STD} ${GS_FONTS_OTHER} ${PDF_SEC}

#  Note: the following two are special files.  In the 5.50 directory
#  on the FTP site, there are symlinks:
#        ghostscript-fonts-other-5.50.tar.gz ->
#               ../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.10a.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz

# PostScript source to decode encrypted PDF files
PDF_SEC=	pdf_sec.ps

post-extract:	common-post-extract
	${RM} -f ${WRKSRC}/${PDF_SEC}
	${LN} -s ${_DISTDIR}/${PDF_SEC} ${WRKSRC}/${PDF_SEC}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/ghostscript
	cd ${PREFIX}/share/ghostscript; \
		${PAX} -zrf ${_DISTDIR}/${GS_FONTS_STD}
	cd ${PREFIX}/share/ghostscript/fonts; \
		${PAX} -zrf ${_DISTDIR}/${GS_FONTS_OTHER}

post-install:
	${LN} -sf gs.1 ${PREFIX}/man/man1/gstty.1
	${MV} ${PREFIX}/bin/gs ${PREFIX}/bin/gstty
	strip ${PREFIX}/bin/gstty

.include "../../print/ghostscript5/Makefile.common"
