# $NetBSD: Makefile,v 1.4 2016/01/26 11:23:04 markd Exp $

DISTNAME=	seminar.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-seminar
LICENSE=	lppl-1.2

CONFLICTS+=	teTeX-texmf<=3.0nb30

REPLACE_SH+=	doc/latex/seminar/run.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
