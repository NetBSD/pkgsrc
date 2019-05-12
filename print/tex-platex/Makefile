# $NetBSD: Makefile,v 1.7 2019/05/12 04:16:32 markd Exp $

DISTNAME=	platex
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50831

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
