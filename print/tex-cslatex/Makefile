# $NetBSD: Makefile,v 1.8 2023/06/17 11:40:31 markd Exp $

DISTNAME=	cslatex
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	67061

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cslatex
COMMENT=	LaTeX support for Czech/Slovak typesetting
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-csplain-[0-9]*:../../print/tex-csplain
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

#INSTALLATION_DIRS+=	bin

#TEX_FORMATS+=	"cslatex pdftex - -etex cslatex.ini\\npdfcslatex pdftex - -etex cslatex.ini\\n"

.include "../../print/texlive/package.mk"

#post-install:
#	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/cslatex
#	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdfcslatex

.include "../../mk/bsd.pkg.mk"
