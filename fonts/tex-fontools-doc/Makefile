# $NetBSD: Makefile,v 1.23 2026/02/10 08:36:00 markd Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2025.76266
TEXLIVE_REV=	76266

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	texmf-dist/doc/support/fontools/splitttc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
