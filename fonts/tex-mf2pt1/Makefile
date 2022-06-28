# $NetBSD: Makefile,v 1.12 2022/06/28 11:33:54 wiz Exp $

DISTNAME=	mf2pt1
PKGNAME=	tex-${DISTNAME}-2.7
PKGREVISION=	1
TEXLIVE_REV=	61217

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mf2pt1
COMMENT=	Convert stylized Metafont to PostScript Type 1
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
