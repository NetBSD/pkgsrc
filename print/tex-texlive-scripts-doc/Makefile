# $NetBSD: Makefile,v 1.6 2023/04/11 00:09:23 markd Exp $

DISTNAME=	texlive-scripts.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2023
TEXLIVE_REV=	66797

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts
LICENSE=	gnu-gpl-v2 AND public-domain

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/install-tl.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
