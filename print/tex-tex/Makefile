# $NetBSD: Makefile,v 1.11 2019/12/06 20:23:26 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
