# $NetBSD: Makefile,v 1.5 2020/01/18 23:33:47 rillig Exp $

DISTNAME=	cjkutils.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.8.4
TEXLIVE_REV=	47198

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk
COMMENT=	Documentation for tex-cjkutils
LICENSE=	gnu-gpl-v2

#TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
