# $NetBSD: Makefile,v 1.1.1.1 2000/06/26 02:27:41 hubertf Exp $
#

DISTNAME=	jadetex-2.20
CATEGORIES=	print
MASTER_SITES=	http://www.tug.org/applications/jadetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	hugelatex-1.0:../hugelatex

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-jadetex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd ${WRKSRC}; \
	${MAKE} ${.MAKEFLAGS}; \
	${MAKE} ${.MAKEFLAGS} install; \
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

.include "../../mk/bsd.pkg.mk"
