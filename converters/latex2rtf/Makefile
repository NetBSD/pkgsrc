# $NetBSD: Makefile,v 1.3 2001/08/20 04:06:48 jlam Exp $
#

DISTNAME=	latex2rtf-1.8aa
PKGNAME=	latex2rtf-1.8a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.kfa-juelich.de/isr/1/texconv/latex2rtf.html
COMMENT=	LaTeX to RTF converter

USE_BUILDLINK_ONLY=	# defined
MAKE_FLAGS+=		CC="${CC}"
MAKE_FLAGS+=		XCFLAGS="${CFLAGS}"

INFO_FILES=	latex2rtf.info

INSTALL_TARGET=	simple_install simple_cfg_install

post-extract:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.in
	${RM} -f ${WRKSRC}/*.o

do-configure:
	${SED} < ${WRKSRC}/${MAKEFILE}.in > ${WRKSRC}/${MAKEFILE} \
		-e 's:@PREFIX@:${PREFIX}:'

post-install:
	for f in ${INFO_FILES}; do ${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info/$$f; done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/latex2rtf
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.html ${PREFIX}/share/doc/latex2rtf/latex2rtf.html
	${INSTALL_DATA} ${WRKSRC}/doc/l2r.pdf ${PREFIX}/share/doc/latex2rtf/latex2rtf.pdf

.include "../../mk/bsd.pkg.mk"
