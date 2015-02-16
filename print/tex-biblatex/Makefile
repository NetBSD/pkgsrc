# $NetBSD: Makefile,v 1.3 2015/02/16 17:27:44 nros Exp $

.include "Makefile.common"

PKGNAME=	tex-${DISTNAME:S/.tds//}

COMMENT=	Bibliographies in LaTeX using BibTeX for sorting only

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-logreq>=1.0:../../print/tex-logreq
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	p5-biblatex-biber>=1.9:../../print/p5-biblatex-biber

do-install:
	cd ${WRKSRC} && \
	${PAX} -rwpm bibtex ${DESTDIR}${PREFIX}/share/texmf-dist && \
	${PAX} -rwpm tex ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
