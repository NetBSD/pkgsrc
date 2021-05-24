# $NetBSD: Makefile,v 1.16 2021/05/24 19:52:14 wiz Exp $

DISTNAME=	fontools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020.57171
PKGREVISION=	1
TEXLIVE_REV=	57171

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Documentation for tex-fontools
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl
REPLACE_PERL+=	texmf-dist/doc/support/fontools/splitttc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
