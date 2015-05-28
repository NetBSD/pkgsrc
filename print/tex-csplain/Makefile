# $NetBSD: Makefile,v 1.1 2015/05/28 11:55:19 markd Exp $

DISTNAME=	csplain
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35901

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csplain
COMMENT=	Plain TeX multilanguage support
#LICENSE=	other-free

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"csplain pdftex -etex -enc csplain-utf8.ini\\npdfcsplain pdftex -etex -enc csplain-utf8.ini\\n"

# execute AddFormat name=pdfcsplain engine=xetex        options="-etex csplain.ini"
# execute AddFormat name=pdfcsplain engine=luatex       options="-etex csplain.ini"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/csplain
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfcsplain

.include "../../mk/bsd.pkg.mk"
