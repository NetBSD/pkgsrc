# $NetBSD: Makefile,v 1.14 2021/06/06 02:04:52 markd Exp $

DISTNAME=	tex
PKGNAME=	tex-${DISTNAME}-3.141592653
TEXLIVE_REV=	57972

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tex
COMMENT=	Plain TeX format
#LICENSE=	knuth

DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c
SUPERSEDES=	tex-bin-tex<2009

TEX_FORMATS+=	"tex tex - tex.ini\\n"
TEX_TEXMF_DIRS=	# empty

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
