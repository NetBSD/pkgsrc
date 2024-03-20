# $NetBSD: Makefile,v 1.2 2024/03/20 09:56:41 markd Exp $

DISTNAME=	currfile
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	70650

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/currfile
COMMENT=	Provide file name and path of input files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
