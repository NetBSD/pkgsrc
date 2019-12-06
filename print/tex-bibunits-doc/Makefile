# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:01 markd Exp $

DISTNAME=	bibunits.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.2
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-bibunits
LICENSE=	lppl-1.3c

REPLACE_SH+=	doc/latex/bibunits/bibtexall

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
