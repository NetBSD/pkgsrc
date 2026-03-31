# $NetBSD: Makefile,v 1.3 2026/03/31 09:03:57 markd Exp $

DISTNAME=	rerunfilecheck
PKGNAME=	tex-${DISTNAME}-1.11
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/rerunfilecheck
COMMENT=	Checksum based rerun checks on auxiliary files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-uniquecounter-[0-9]*:../../print/tex-uniquecounter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
