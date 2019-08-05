# $NetBSD: Makefile,v 1.14 2019/08/05 11:01:28 markd Exp $

DISTNAME=	csplain
PKGNAME=	tex-${DISTNAME}-2019.51317
TEXLIVE_REV=	51317

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csplain
COMMENT=	Plain TeX multilanguage support
#LICENSE=	other-free

DEPENDS+=	tex-cs-[0-9]*:../../fonts/tex-cs
DEPENDS+=	tex-enctex-[0-9]*:../../print/tex-enctex
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
