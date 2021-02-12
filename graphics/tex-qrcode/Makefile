# $NetBSD: Makefile,v 1.1 2021/02/12 02:52:06 markd Exp $

DISTNAME=	qrcode
PKGNAME=	tex-${DISTNAME}-1.51
TEXLIVE_REV=	36065

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/qrcode
COMMENT=	Generate QR codes in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
