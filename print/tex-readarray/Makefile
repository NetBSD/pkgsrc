# $NetBSD: Makefile,v 1.5 2019/03/06 21:36:04 joerg Exp $

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

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
