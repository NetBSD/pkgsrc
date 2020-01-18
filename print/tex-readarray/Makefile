# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:44 rillig Exp $

DISTNAME=	readarray
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	42467

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/readarray
COMMENT=	Read, store and recall array-formatted data
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifnextok-[0-9]*:../../print/tex-ifnextok
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
