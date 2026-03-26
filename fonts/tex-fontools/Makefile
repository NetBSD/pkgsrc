# $NetBSD: Makefile,v 1.28 2026/03/26 09:03:20 markd Exp $

DISTNAME=	fontools
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78330

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontools
COMMENT=	Tools to simplify using fonts (especially TT/OTF ones)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/afm2afm bin/autoinst bin/ot2kpx

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/fontools/* ${WRKSRC}/bin/
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
