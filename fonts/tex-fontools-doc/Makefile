# $NetBSD: Makefile,v 1.25 2026/03/26 09:03:20 markd Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2026
TEXLIVE_REV=	78330

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	texmf-dist/doc/support/fontools/splitttc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
