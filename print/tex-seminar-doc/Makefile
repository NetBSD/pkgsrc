# $NetBSD: Makefile,v 1.6 2019/12/06 20:23:15 markd Exp $

DISTNAME=	seminar.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-seminar
LICENSE=	lppl-1.2

REPLACE_SH+=	doc/latex/seminar/run.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
