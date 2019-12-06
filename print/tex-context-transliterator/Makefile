# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:18 markd Exp $

DISTNAME=	context-transliterator
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	29801

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-transliterator
COMMENT=	Transliterate text from 'other' alphabets
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
