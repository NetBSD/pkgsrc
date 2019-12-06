# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:13 markd Exp $

DISTNAME=	context-animation
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	36188

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-animation
COMMENT=	Generate fieldstack based animation with ConTeXt
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
