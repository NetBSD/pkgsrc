# $NetBSD: Makefile,v 1.9 2003/09/22 09:06:35 wiz Exp $
#

DISTNAME=	latex2rtf-1.8aa
PKGNAME=	latex2rtf-1.8a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.kfa-juelich.de/isr/1/texconv/latex2rtf.html
COMMENT=	LaTeX to RTF converter

USE_BUILDLINK2=	# defined
MAKE_FLAGS+=	XCFLAGS="${CFLAGS}"

INFO_FILES=	latex2rtf.info
SUPPORT_FILES=	direct.cfg fonts.cfg ignore.cfg english.cfg german.cfg \
		spanish.cfg

post-extract:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/*.o

do-configure:
	${SED} < ${WRKSRC}/${MAKEFILE}.in > ${WRKSRC}/${MAKEFILE} \
		-e 's:@PREFIX@:${PREFIX}:'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/latex2rtf ${PREFIX}/bin/latex2rtf
	${INSTALL_MAN} ${WRKSRC}/latex2rtf.1 ${PREFIX}/man/man1/latex2rtf.1
	${INSTALL_DATA} ${WRKSRC}/doc/latex2rtf.info ${PREFIX}/info/latex2rtf.info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/latex2rtf
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.html ${PREFIX}/share/doc/latex2rtf/latex2rtf.html
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.pdf ${PREFIX}/share/doc/latex2rtf/latex2rtf.pdf
	${INSTALL_DATA_DIR} ${PREFIX}/share/latex2rtf
.for FILE in ${SUPPORT_FILES}
	${INSTALL_DATA} ${WRKSRC}/cfg/${FILE} ${PREFIX}/share/latex2rtf/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
