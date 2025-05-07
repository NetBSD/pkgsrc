# $NetBSD: Makefile,v 1.13 2025/05/07 20:38:35 markd Exp $

DISTNAME=	eplain
PKGNAME=	tex-${DISTNAME}-3.14
TEXLIVE_REV=	71409

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/eplain
COMMENT=	Extended plain TeX macros
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini\\n" 

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/eplain

.include "../../mk/bsd.pkg.mk"
