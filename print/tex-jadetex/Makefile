# $NetBSD: Makefile,v 1.2 2001/11/29 01:12:46 hubertf Exp $
#

DISTNAME=	jadetex-2.20
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.tug.org/applications/jadetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Process tex files produced by the TeX backend of Jade

DEPENDS+=	tex-hugelatex-1.0:../tex-hugelatex

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-jadetex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd ${WRKSRC}; ${SETENV} TEXFORMATS=${LOCALBASE}/share/texmf/web2c \
		${MAKE} ${MAKEFLAGS};
	cd ${WRKSRC}; ${SETENV} TEXFORMATS=${LOCALBASE}/share/texmf/web2c \
		${MAKE} ${MAKEFLAGS} install
	${RM} -f ${PREFIX}/bin/jadetex
	${LN} -s tex ${PREFIX}/bin/jadetex
	${RM} -f ${PREFIX}/bin/pdfjadetex
	${LN} -s pdftex ${PREFIX}/bin/pdfjadetex
	${PREFIX}/bin/mktexlsr
	${INSTALL_MAN} ${WRKSRC}/jadetex.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pdfjadetex.1 ${PREFIX}/man/man1
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/jadetex
	for i in ${WRKSRC}/doc/* ; do \
		${INSTALL_MAN} $$i ${PREFIX}/share/doc/jadetex; \
	done
	${INSTALL_MAN_DIR} ${PREFIX}/share/examples/jadetex
	for i in ${WRKSRC}/test/* ; do \
		${INSTALL_MAN} $$i ${PREFIX}/share/examples/jadetex; \
	done
	:
	: Complete the set that the textproc/jade pkg started. We
	: use our files here as that is what the jadetex.fmt file is
	: really made from:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/jadetex.dtx ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/jadetex.ini ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/jadetex.ins ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/pdfjadetex.ini ${PREFIX}/share/sgml/jade

.include "../../mk/bsd.pkg.mk"
