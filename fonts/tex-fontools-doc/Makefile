# $NetBSD: Makefile,v 1.11 2019/12/06 19:30:00 markd Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2019.51625
TEXLIVE_REV=	51625

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl
REPLACE_PERL+=	texmf-dist/doc/support/fontools/splitttc

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
