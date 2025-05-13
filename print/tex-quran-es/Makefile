# $NetBSD: Makefile,v 1.1 2025/05/13 10:51:36 markd Exp $

DISTNAME=	quran-es
PKGNAME=	tex-${DISTNAME}-0.11
TEXLIVE_REV=	74874

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quran-es
COMMENT=	Spanish Translations for the quran package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
