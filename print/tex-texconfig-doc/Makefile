# $NetBSD: Makefile,v 1.4 2017/06/21 13:25:33 markd Exp $

DISTNAME=	texconfig.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44166

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texconfig
COMMENT=	Documentation for tex-texconfig

CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
