# $NetBSD: Makefile,v 1.6 2019/01/28 08:52:43 markd Exp $

DISTNAME=	platex
PKGNAME=	tex-${DISTNAME}-2018.49292
TEXLIVE_REV=	49292

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/platex
COMMENT=	pLaTeX2e and miscellaneous macros for pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-[0-9]*:../../print/tex-ptex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"platex eptex language.dat *platex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf eptex ${DESTDIR}${PREFIX}/bin/platex

.include "../../mk/bsd.pkg.mk"
