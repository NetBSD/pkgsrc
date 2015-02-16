# $NetBSD: Makefile,v 1.2 2015/02/16 17:31:32 nros Exp $

.include "../../print/tex-biblatex/Makefile.common"

PKGNAME=	tex-${DISTNAME:S/.tds//:S/-/-doc-/}

COMMENT=	Documentation for tex-biblatex

do-install:
	cd ${WRKSRC}/doc && \
	${PAX} -rwpm latex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc && \
	${INSTALL_DATA} ${WRKSRC}/doc/biblatex.pdf \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/biblatex

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
