# $NetBSD: Makefile,v 1.17 2022/03/28 21:38:32 riastradh Exp $

DISTNAME=	media9
PKGNAME=	tex-${DISTNAME}-1.15
PKGREVISION=	1
TEXLIVE_REV=	58025

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/media9
COMMENT=	Multimedia inclusion package with Adobe Reader-9/X compatibility
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-ocgx2-[0-9]*:../../print/tex-ocgx2
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
