# $NetBSD: Makefile,v 1.5 2017/09/06 10:40:32 wiz Exp $

DISTNAME=	texconfig.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44166

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ctan.org/pkg/texconfig
COMMENT=	Documentation for tex-texconfig

CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
