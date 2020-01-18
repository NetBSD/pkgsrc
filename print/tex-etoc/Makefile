# $NetBSD: Makefile,v 1.4 2020/01/18 23:34:06 rillig Exp $

DISTNAME=	etoc
PKGNAME=	tex-${DISTNAME}-1.09
TEXLIVE_REV=	50317

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etoc
COMMENT=	Completely customisable TOCs
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
