# $NetBSD: Makefile,v 1.19 2022/09/06 21:01:16 markd Exp $

DISTNAME=	media9
PKGNAME=	tex-${DISTNAME}-1.25
TEXLIVE_REV=	64047

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
