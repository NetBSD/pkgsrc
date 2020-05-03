# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:43 markd Exp $

DISTNAME=	rerunfilecheck
PKGNAME=	tex-${DISTNAME}-1.9
TEXLIVE_REV=	54841

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/rerunfilecheck
COMMENT=	Checksum based rerun checks on auxiliary files
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-uniquecounter-[0-9]*:../../print/tex-uniquecounter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
