# $NetBSD: Makefile,v 1.1 2019/02/02 02:44:20 markd Exp $

DISTNAME=	bigfoot
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	38248

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bigfoot
COMMENT=	Footnotes for critical editions
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-ncctools-[0-9]*:../../print/tex-ncctools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
