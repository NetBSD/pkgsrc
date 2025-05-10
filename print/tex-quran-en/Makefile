# $NetBSD: Makefile,v 1.2 2025/05/10 23:08:51 markd Exp $

DISTNAME=	quran-en
PKGNAME=	tex-${DISTNAME}-0.11
TEXLIVE_REV=	74874

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quran-en
COMMENT=	English translation extension to the quran package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
