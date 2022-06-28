# $NetBSD: Makefile,v 1.30 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	glossaries
PKGNAME=	tex-${DISTNAME}-4.49
PKGREVISION=	1
TEXLIVE_REV=	60921

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/glossaries
COMMENT=	Create glossaries and lists of acronyms
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-supertabular-[0-9]*:../../print/tex-supertabular
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-tracklang-[0-9]*:../../print/tex-tracklang
DEPENDS+=	tex-xfor-[0-9]*:../../print/tex-xfor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/makeglossaries

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/glossaries/makeglossaries \
		${WRKSRC}/bin/
	${RM} -rf ${WRKSRC}/texmf-dist/scripts/glossaries/makeglossaries.bat
	${RM} -rf ${WRKSRC}/texmf-dist/scripts/glossaries/makeglossaries-lite.lua

.include "../../mk/bsd.pkg.mk"
