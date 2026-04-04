# $NetBSD: Makefile,v 1.4 2026/04/04 05:12:57 markd Exp $

DISTNAME=	texlive-scripts-extra.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2026
TEXLIVE_REV=	78162

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-scripts-extra
LICENSE=	gnu-gpl-v2 AND public-domain

# remove manual pages installed by web2c
post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mkocp.1
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mkofm.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
