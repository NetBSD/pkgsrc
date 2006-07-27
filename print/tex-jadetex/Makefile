# $NetBSD: Makefile,v 1.24 2006/07/27 00:09:06 hubertf Exp $
#

DISTNAME=	jadetex-3.13
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jadetex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jadetex.sourceforge.net/
COMMENT=	Process tex files produced by the TeX backend of Jade

DEPENDS+=	tex-hugelatex>=1.0nb1:../../print/tex-hugelatex

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/jadetex \
			share/sgml/jade
NO_BUILD=	yes
TEXMF_CNF=	${PKG_TEXMFPREFIX}/web2c/texmf.cnf
CHECK_FILES_SKIP += ${PREFIX}/share/texmf/web2c/texmf.cnf-before-jadetex

.include "../../print/teTeX/module.mk"

do-install:
	${CP} -p ${TEXMF_CNF} ${TEXMF_CNF}-before-jadetex
	${CAT} ${FILESDIR}/texmf.cnf-add >>${TEXMF_CNF}
	cd ${WRKSRC}; ${SETENV} TEX=${TEX} PDFTEX=${PDFTEX} \
		TEXFORMATS=${LOCALBASE}/share/texmf-var/web2c \
	       ${MAKE} ${MAKEFLAGS};
	cd ${WRKSRC}; ${SETENV} TEX=${TEX} PDFTEX=${PDFTEX} \
       		TEXFORMATS=${LOCALBASE}/share/texmf-var/web2c \
	       ${MAKE} ${MAKEFLAGS} install
	:
	${RM} -f ${PREFIX}/bin/jadetex
	${LN} -s ${TEX} ${PREFIX}/bin/jadetex
	${RM} -f ${PREFIX}/bin/pdfjadetex
	${LN} -s ${PDFTEX} ${PREFIX}/bin/pdfjadetex
	${INSTALL_MAN} ${WRKSRC}/jadetex.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/pdfjadetex.1 ${PREFIX}/${PKGMANDIR}/man1
	for i in ${WRKSRC}/doc/* ; do \
		${INSTALL_MAN} $$i ${PREFIX}/share/doc/jadetex; \
	done
	:
	: Complete the set that the textproc/jade pkg started. We
	: use our files here as that is what the jadetex.fmt file is
	: really made from:
	${INSTALL_DATA} ${WRKSRC}/jadetex.dtx ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/jadetex.ini ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/jadetex.ins ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/pdfjadetex.ini ${PREFIX}/share/sgml/jade

.include "../../mk/bsd.pkg.mk"
