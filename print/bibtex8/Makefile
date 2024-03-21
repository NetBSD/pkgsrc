# $NetBSD: Makefile,v 1.2 2024/03/21 08:09:47 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	bibtex8-4.02
CATEGORIES=	print

HOMEPAGE=	https://ctan.org/pkg/bibtex8
COMMENT=	BibTeX variant supporting 8-bit encodings
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/bibtex-x

USE_LANGUAGES=	c99 c++11
USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/bibtex-x

CONFIGURE_ARGS+=	--disable-bibtexu
CONFIGURE_ARGS+=	--with-system-kpathsea

# KPATHSEA_LIBS doesn't get set up correctly
# when --disable-bibtexu is passed to configure
# so pass it explicitly
BUILD_MAKE_FLAGS+=	KPATHSEA_LIBS+=-lkpathsea

post-install:
	rm ${DESTDIR}${PREFIX}/man/man1/bibtexu.1
	rm -rf ${DESTDIR}${PREFIX}/share/texmf-dist/doc/bibtexu

.include "../../print/kpathsea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
