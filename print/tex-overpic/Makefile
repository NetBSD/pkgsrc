# $NetBSD: Makefile,v 1.7 2019/12/06 20:22:59 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-1.2
PKGREVISION=	1
TEXLIVE_REV=	48550

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
