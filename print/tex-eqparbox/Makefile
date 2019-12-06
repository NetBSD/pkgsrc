# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:31 markd Exp $

DISTNAME=	eqparbox
PKGNAME=	tex-${DISTNAME}-4.1
TEXLIVE_REV=	45215

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eqparbox
COMMENT=	Create equal-widthed parboxes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
