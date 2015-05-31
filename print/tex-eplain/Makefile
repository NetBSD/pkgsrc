# $NetBSD: Makefile,v 1.1 2015/05/31 06:45:32 markd Exp $

DISTNAME=	eplain
PKGNAME=	tex-${DISTNAME}-3.7
TEXLIVE_REV=	36217

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eplain
COMMENT=	Extended plain TeX macros
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb55
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=   "eplain pdftex language.dat -translate-file=cp227.tcx *eplain.ini\\n" 

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/eplain

.include "../../mk/bsd.pkg.mk"
