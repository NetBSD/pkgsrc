# $NetBSD: Makefile,v 1.18 2022/04/09 21:00:13 markd Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2021.61726
TEXLIVE_REV=	61726

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	texmf-dist/doc/support/fontools/splitttc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
