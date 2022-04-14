# $NetBSD: Makefile,v 1.3 2022/04/14 07:01:35 markd Exp $

DISTNAME=	zref
PKGNAME=	tex-${DISTNAME}-2.34
TEXLIVE_REV=	62977

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/zref
COMMENT=	New reference scheme for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-etexcmds-[0-9]*:../../print/tex-etexcmds
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-uniquecounter-[0-9]*:../../print/tex-uniquecounter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
