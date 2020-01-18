# $NetBSD: Makefile,v 1.7 2020/01/18 23:33:52 rillig Exp $

DISTNAME=	context-filter
PKGNAME=	tex-${DISTNAME}-2018.48390
TEXLIVE_REV=	48390

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-filter
COMMENT=	Run external programs on the contents of a start-stop environment
LICENSE=	2-clause-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
