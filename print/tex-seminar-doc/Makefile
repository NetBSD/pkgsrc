# $NetBSD: Makefile,v 1.3 2015/04/27 16:05:20 joerg Exp $

DISTNAME=	seminar.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-seminar

CONFLICTS+=	teTeX-texmf<=3.0nb30

REPLACE_SH+=	doc/latex/seminar/run.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
