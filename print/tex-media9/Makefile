# $NetBSD: Makefile,v 1.12 2019/12/06 20:21:59 markd Exp $

DISTNAME=	media9
PKGNAME=	tex-${DISTNAME}-1.02
TEXLIVE_REV=	51619

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/media9
COMMENT=	Multimedia inclusion package with Adobe Reader-9/X compatibility
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
