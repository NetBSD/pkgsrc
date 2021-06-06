# $NetBSD: Makefile,v 1.4 2021/06/06 23:29:22 markd Exp $

DISTNAME=	texlive-scripts.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2021
TEXLIVE_REV=	59470

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts
LICENSE=	gnu-gpl-v2 AND public-domain

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/install-tl.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
