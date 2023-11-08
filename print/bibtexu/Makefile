# $NetBSD: Makefile,v 1.3 2023/11/08 13:20:40 wiz Exp $

PKGREVISION= 2
.include "../../print/texlive/Makefile.common"

PKGNAME=	bibtexu-4.00
CATEGORIES=	print

HOMEPAGE=	https://ctan.org/pkg/bibtexu
COMMENT=	BibTeX variant supporting Unicode (UTF-8), via ICU
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/bibtex-x

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/bibtex-x

CONFIGURE_ARGS+=	--disable-bibtex8
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--with-system-kpathsea

post-install:
	rm ${DESTDIR}${PREFIX}/man/man1/bibtex8.1
	rm -rf ${DESTDIR}${PREFIX}/share/texmf-dist/bibtex/csf
	rm -rf ${DESTDIR}${PREFIX}/share/texmf-dist/doc/bibtex8

.include "../../print/kpathsea/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
