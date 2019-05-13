# $NetBSD: Makefile,v 1.11 2019/05/13 11:48:11 markd Exp $

DISTNAME=	fontools
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50982

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
