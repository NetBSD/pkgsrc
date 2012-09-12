# $NetBSD: Makefile,v 1.1 2012/09/12 16:00:31 is Exp $

DISTNAME=	shadethm
PKGNAME=	tex-${DISTNAME}-20101030
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip
LICENSE=	lppl-1.3c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/shadethm/
COMMENT=	Theorem environments that are shaded.

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/shadethm \
			share/texmf-dist/tex/latex/shadethm

.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/shadethm.sty ${WRKSRC}/colored.sth \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/shadethm/
	${INSTALL_DATA} ${WRKSRC}/1st_read.me \
			${WRKSRC}/shadetest.tex \
			${WRKSRC}/shadetest.pdf \
			${WRKSRC}/shadethm-doc.tex \
			${WRKSRC}/shadethm-doc.pdf \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/shadethm/

.include "../../mk/bsd.pkg.mk"
