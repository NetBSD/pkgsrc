# $NetBSD: Makefile,v 1.20 2023/04/02 11:12:48 markd Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2022
TEXLIVE_REV=	65706

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	texmf-dist/doc/support/fontools/splitttc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
