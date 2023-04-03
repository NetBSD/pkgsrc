# $NetBSD: Makefile,v 1.1 2023/04/03 11:37:17 markd Exp $

DISTNAME=	currfile
PKGNAME=	tex-${DISTNAME}-0.8
TEXLIVE_REV=	64673

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/currfile
COMMENT=	Provide file name and path of input files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
