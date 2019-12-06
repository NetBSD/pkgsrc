# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:19 markd Exp $

DISTNAME=	continue
PKGNAME=	tex-${DISTNAME}-0.2
TEXLIVE_REV=	49449

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/continue
COMMENT=	Prints 'continuation' marks on recto pages of multipage documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
