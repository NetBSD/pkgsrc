# $NetBSD: Makefile,v 1.5 2022/04/17 10:23:51 markd Exp $

DISTNAME=	texlive-scripts.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2022
TEXLIVE_REV=	63029

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts
LICENSE=	gnu-gpl-v2 AND public-domain

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/install-tl.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
