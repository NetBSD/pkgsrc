# $NetBSD: Makefile,v 1.16 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	latex2rtf-1.8aa
PKGNAME=	latex2rtf-1.8a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2rtf/} \
		${MASTER_SITE_SOURCEFORGE:=latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://latex2rtf.sourceforge.net/
COMMENT=	LaTeX to RTF converter

MAKE_FLAGS+=	XCFLAGS="${CFLAGS}"

INFO_FILES=	latex2rtf.info
SUPPORT_FILES=	direct.cfg fonts.cfg ignore.cfg english.cfg german.cfg \
		spanish.cfg

INSTALLATION_DIRS=	bin ${INFO_DIR} man/man1

post-extract:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/*.o

do-configure:
	${SED} < ${WRKSRC}/Makefile.in > ${WRKSRC}/Makefile \
		-e 's:@PREFIX@:${PREFIX}:'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/latex2rtf ${PREFIX}/bin/latex2rtf
	${INSTALL_MAN} ${WRKSRC}/latex2rtf.1 ${PREFIX}/man/man1/latex2rtf.1
	${INSTALL_DATA} ${WRKSRC}/doc/latex2rtf.info ${PREFIX}/${INFO_DIR}/latex2rtf.info
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/latex2rtf
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.html ${PREFIX}/share/doc/latex2rtf/latex2rtf.html
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.pdf ${PREFIX}/share/doc/latex2rtf/latex2rtf.pdf
	${INSTALL_DATA_DIR} ${PREFIX}/share/latex2rtf
.for FILE in ${SUPPORT_FILES}
	${INSTALL_DATA} ${WRKSRC}/cfg/${FILE} ${PREFIX}/share/latex2rtf/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
