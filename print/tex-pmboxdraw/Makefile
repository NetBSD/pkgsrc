# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:43 markd Exp $

DISTNAME=	pmboxdraw
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	53046

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pmboxdraw
COMMENT=	Poor man's box drawing characters
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
