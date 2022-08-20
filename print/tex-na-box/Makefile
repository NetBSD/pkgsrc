# $NetBSD: Makefile,v 1.1 2022/08/20 21:37:16 wiz Exp $

DISTNAME=	na-box
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	45130

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/na-box
COMMENT=	Arabic-aware version of pas-cours package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
