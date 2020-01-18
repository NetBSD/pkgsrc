# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:45 rillig Exp $

DISTNAME=	chemgreek
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	42758

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/chemgreek
COMMENT=	Upright Greek letters in chemistry
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
