# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:55 markd Exp $

DISTNAME=	longfbox
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	39028

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/longfbox
COMMENT=	Draw framed boxes with standard CSS attributes that can break over multiple pages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ellipse-[0-9]*:../../graphics/tex-ellipse
DEPENDS+=	tex-mdwtools-[0-9]*:../../print/tex-mdwtools
DEPENDS+=	tex-options-[0-9]*:../../print/tex-options
DEPENDS+=	tex-pict2e-[0-9]*:../../print/tex-pict2e

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
