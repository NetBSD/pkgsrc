# $NetBSD: Makefile,v 1.1 2017/01/20 21:44:00 markd Exp $

DISTNAME=	options
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	39030

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/options
COMMENT=	Provides convenient key-value options for LaTeX package writers
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
