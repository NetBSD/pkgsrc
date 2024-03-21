# $NetBSD: Makefile,v 1.1 2024/03/21 19:51:21 markd Exp $

DISTNAME=	quran-en
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	68790

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quran-en
COMMENT=	English translation extension to the quran package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-quran-[0-9]*:../../print/tex-quran
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
