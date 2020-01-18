# $NetBSD: Makefile,v 1.5 2020/01/18 23:33:57 rillig Exp $

DISTNAME=	cslatex
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	2
TEXLIVE_REV=	28596

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cslatex
COMMENT=	LaTeX support for Czech/Slovak typesetting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-csplain-[0-9]*:../../print/tex-csplain
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"cslatex pdftex - -etex cslatex.ini\\npdfcslatex pdftex - -etex cslatex.ini\\n"

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/cslatex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfcslatex

.include "../../mk/bsd.pkg.mk"
