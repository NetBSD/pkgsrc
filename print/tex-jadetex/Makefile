# $NetBSD: Makefile,v 1.11 2004/09/29 13:10:23 hubertf Exp $
#

DISTNAME=	jadetex-3.13
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jadetex/}

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Process tex files produced by the TeX backend of Jade

DEPENDS+=	tex-hugelatex>=1.0nb1:../tex-hugelatex

NO_BUILD=	yes
TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-jadetex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd ${WRKSRC}; ${SETENV} TEXFORMATS=${LOCALBASE}/share/texmf/web2c \
	       ${MAKE} ${MAKEFLAGS};
	cd ${WRKSRC}; ${SETENV} TEXFORMATS=${LOCALBASE}/share/texmf/web2c \
	       ${MAKE} ${MAKEFLAGS} install
	:
	${RM} -f ${PREFIX}/bin/jadetex
	${LN} -s tex ${PREFIX}/bin/jadetex
	${RM} -f ${PREFIX}/bin/pdfjadetex
	${LN} -s pdftex ${PREFIX}/bin/pdfjadetex
	${INSTALL_MAN} ${WRKSRC}/jadetex.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/pdfjadetex.1 ${PREFIX}/man/man1
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/jadetex
	for i in ${WRKSRC}/doc/* ; do \
		${INSTALL_MAN} $$i ${PREFIX}/share/doc/jadetex; \
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
	${PREFIX}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
