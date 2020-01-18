# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:56 rillig Exp $

DISTNAME=	continue
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	49449

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/continue
COMMENT=	Prints 'continuation' marks on recto pages of multipage documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
