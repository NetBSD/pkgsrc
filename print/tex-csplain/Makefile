# $NetBSD: Makefile,v 1.17 2020/05/10 04:31:57 markd Exp $

DISTNAME=	csplain
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	1
TEXLIVE_REV=	54699

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csplain
COMMENT=	Plain TeX multilanguage support
#LICENSE=	other-free

DEPENDS+=	tex-cs-[0-9]*:../../fonts/tex-cs
DEPENDS+=	tex-enctex-[0-9]*:../../print/tex-enctex
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"csplain pdftex - -etex -enc csplain-utf8.ini\\npdfcsplain pdftex - -etex -enc csplain-utf8.ini\\n"

# execute AddFormat name=pdfcsplain engine=xetex        options="-etex csplain.ini"
# execute AddFormat name=pdfcsplain engine=luatex       options="-etex csplain.ini"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/csplain
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfcsplain

.include "../../mk/bsd.pkg.mk"
