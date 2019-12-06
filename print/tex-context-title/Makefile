# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:18 markd Exp $

DISTNAME=	context-title
PKGNAME=	tex-${DISTNAME}-2018	# actually 2012.04.11
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-title
COMMENT=	ConTeXt document titles
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
