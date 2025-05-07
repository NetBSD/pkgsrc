# $NetBSD: Makefile,v 1.7 2025/05/07 20:32:39 markd Exp $

DISTNAME=	amstex
PKGNAME=	tex-${DISTNAME}-2.2.73848
TEXLIVE_REV=	73848

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/amstex
COMMENT=	American Mathematical Society plain TeX macros
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"amstex pdftex - -translate-file=cp227.tcx *amstex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/amstex

.include "../../mk/bsd.pkg.mk"
