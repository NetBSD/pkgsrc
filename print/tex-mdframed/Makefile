# $NetBSD: Makefile,v 1.1 2014/01/07 08:24:57 minskim Exp $

DISTNAME=	mdframed
PKGNAME=	tex-${DISTNAME}-1.9b
TEXLIVE_REV=	31075

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Framed environments that can split at page boundaries
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-needspace-[0-9]*:../../print/tex-needspace
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
