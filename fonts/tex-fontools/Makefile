# $NetBSD: Makefile,v 1.12 2019/08/11 04:50:53 markd Exp $

DISTNAME=	fontools
PKGNAME=	tex-${DISTNAME}-2019.51625
TEXLIVE_REV=	51625

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
