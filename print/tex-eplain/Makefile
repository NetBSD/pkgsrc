# $NetBSD: Makefile,v 1.3 2016/06/16 04:06:03 markd Exp $

DISTNAME=	eplain
PKGNAME=	tex-${DISTNAME}-3.8
TEXLIVE_REV=	41154

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eplain
COMMENT=	Extended plain TeX macros
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb55
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=   "eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini\\n" 

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/eplain

.include "../../mk/bsd.pkg.mk"
