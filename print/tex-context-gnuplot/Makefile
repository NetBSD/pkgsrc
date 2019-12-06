# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:16 markd Exp $

DISTNAME=	context-gnuplot
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	30380

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-gnuplot
COMMENT=	Inclusion of Gnuplot graphs in ConTeXt
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
