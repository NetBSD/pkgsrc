# $NetBSD: Makefile,v 1.8 2022/04/09 07:51:45 markd Exp $

DISTNAME=	readarray
PKGNAME=	tex-${DISTNAME}-3.1
TEXLIVE_REV=	60540

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/readarray
COMMENT=	Read, store and recall array-formatted data
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifnextok-[0-9]*:../../print/tex-ifnextok
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
