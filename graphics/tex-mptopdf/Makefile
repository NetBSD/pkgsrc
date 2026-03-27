# $NetBSD: Makefile,v 1.15 2026/03/27 23:55:51 markd Exp $

DISTNAME=	mptopdf
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	78010

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdf-mps-supp
COMMENT=	Script to convert mpost to PDF
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-supp-pdf<2010
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	web2c>=2010:../../print/web2c
SUPERSEDES+=	tex-supp-pdf<2010

INSTALLATION_DIRS=	bin

TEX_FORMATS+=		"mptopdf pdftex - -translate-file=cp227.tcx mptopdf.tex\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/mptopdf

.include "../../mk/bsd.pkg.mk"
