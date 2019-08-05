# $NetBSD: Makefile,v 1.6 2019/08/05 10:32:45 markd Exp $

DISTNAME=	eplain
PKGNAME=	tex-${DISTNAME}-3.9
TEXLIVE_REV=	51280

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/eplain
COMMENT=	Extended plain TeX macros
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=   "eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini\\n" 

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/eplain

.include "../../mk/bsd.pkg.mk"
