# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:43 rillig Exp $

DISTNAME=	bigfoot
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	38248

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bigfoot
COMMENT=	Footnotes for critical editions
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-ncctools-[0-9]*:../../print/tex-ncctools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
