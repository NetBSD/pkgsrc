# $NetBSD: Makefile,v 1.2 2024/06/24 09:44:34 jperkin Exp $

DISTNAME=	texlive-scripts-extra.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	54744

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts-extra
LICENSE=	gnu-gpl-v2 AND public-domain

# remove manual pages installed by web2c
post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mkocp.1
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mkofm.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
