# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:37 markd Exp $

DISTNAME=	epstopdf-pkg
PKGNAME=	tex-${DISTNAME}-2.11
TEXLIVE_REV=	53546

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/epstopdf-pkg
COMMENT=	Call epstopdf "on the fly"
LICENSE=	lppl-1.3c

DEPENDS+=	tex-grfext-[0-9]*:../../print/tex-grfext
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
