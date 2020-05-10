# $NetBSD: Makefile,v 1.12 2020/05/10 04:31:56 markd Exp $

DISTNAME=	mptopdf
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	1
TEXLIVE_REV=	54276

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdf-mps-supp
COMMENT=	Script to convert mpost to PDF

CONFLICTS+=	tex-supp-pdf<2010
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	web2c>=2010:../../print/web2c
SUPERSEDES+=	tex-supp-pdf<2010

INSTALLATION_DIRS=	bin

TEX_FORMATS+=		"mptopdf pdftex - -translate-file=cp227.tcx mptopdf.tex\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mptopdf

.include "../../mk/bsd.pkg.mk"
