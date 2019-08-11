# $NetBSD: Makefile,v 1.5 2019/08/11 13:21:02 wiz Exp $

DISTNAME=	mf2pt1
PKGNAME=	tex-${DISTNAME}-2.5a
PKGREVISION=	4
TEXLIVE_REV=	33802

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mf2pt1
COMMENT=	Produce PostScript Type 1 fonts from Metafont source
LICENSE=	lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/mf2pt1

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/mf2pt1/mf2pt1.pl \
		${WRKSRC}/bin/mf2pt1
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
