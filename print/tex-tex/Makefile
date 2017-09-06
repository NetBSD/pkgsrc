# $NetBSD: Makefile,v 1.10 2017/09/06 16:49:45 wiz Exp $

DISTNAME=	tex
PKGNAME=	tex-${DISTNAME}-3.14159265
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex
COMMENT=	Plain TeX format
#LICENSE=	knuth

DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c
SUPERSEDES=	tex-bin-tex<2009

TEX_FORMATS+=	"tex tex - tex.ini\\n"
TEX_TEXMF_DIRS=	# empty

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
