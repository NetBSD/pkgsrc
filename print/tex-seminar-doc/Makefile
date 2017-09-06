# $NetBSD: Makefile,v 1.5 2017/09/06 16:49:44 wiz Exp $

DISTNAME=	seminar.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-seminar
LICENSE=	lppl-1.2

REPLACE_SH+=	doc/latex/seminar/run.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
