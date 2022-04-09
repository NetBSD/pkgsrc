# $NetBSD: Makefile,v 1.7 2022/04/09 02:59:57 markd Exp $

DISTNAME=	seminar.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.63a
TEXLIVE_REV=	59801

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/seminar
COMMENT=	Documentation for tex-seminar
LICENSE=	lppl-1.2

REPLACE_SH+=	doc/latex/seminar/run.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
