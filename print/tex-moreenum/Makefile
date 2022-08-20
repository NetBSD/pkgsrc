# $NetBSD: Makefile,v 1.1 2022/08/20 23:20:56 wiz Exp $

DISTNAME=	moreenum
PKGNAME=	tex-${DISTNAME}-1.03
TEXLIVE_REV=	24479

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/moreenum
COMMENT=	More enumeration options
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-alphalph-[0-9]*:../../print/tex-alphalph
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-fmtcount-[0-9]*:../../print/tex-fmtcount
# binhex
DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup
DEPENDS+=	tex-nth-[0-9]*:../../print/tex-nth

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
