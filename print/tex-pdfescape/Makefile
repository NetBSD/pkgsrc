# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:42 markd Exp $

DISTNAME=	pdfescape
PKGNAME=	tex-${DISTNAME}-1.15
TEXLIVE_REV=	53082

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdfescape
COMMENT=	Implements pdfTeX's escape features using TeX or e-TeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
