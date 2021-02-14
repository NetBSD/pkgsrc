# $NetBSD: Makefile,v 1.11 2021/02/14 03:00:49 markd Exp $

DISTNAME=	eplain
PKGNAME=	tex-${DISTNAME}-3.11
TEXLIVE_REV=	57186

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/eplain
COMMENT=	Extended plain TeX macros
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini\\n" 

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/eplain

.include "../../mk/bsd.pkg.mk"
