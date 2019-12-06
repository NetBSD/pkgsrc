# $NetBSD: Makefile,v 1.6 2019/12/06 20:23:10 markd Exp $

DISTNAME=	readarray
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	42467

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/readarray
COMMENT=	Read, store and recall array-formatted data
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifnextok-[0-9]*:../../print/tex-ifnextok
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
