# $NetBSD: Makefile,v 1.10 2024/03/25 10:29:04 markd Exp $

DISTNAME=	texlive-scripts.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024.70742
TEXLIVE_REV=	70742

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts
LICENSE=	gnu-gpl-v2 AND public-domain

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/install-tl.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
