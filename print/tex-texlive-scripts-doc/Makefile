# $NetBSD: Makefile,v 1.8 2024/03/21 11:09:36 markd Exp $

DISTNAME=	texlive-scripts.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024
TEXLIVE_REV=	70709

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts
LICENSE=	gnu-gpl-v2 AND public-domain

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/install-tl.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
