# $NetBSD: Makefile,v 1.4 2016/06/16 03:57:28 markd Exp $

DISTNAME=	fontools
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	38924

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fontools
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
