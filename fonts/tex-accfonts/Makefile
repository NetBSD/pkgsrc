# $NetBSD: Makefile,v 1.8 2020/08/31 18:09:32 wiz Exp $

DISTNAME=	accfonts
PKGNAME=	tex-${DISTNAME}-0.25
PKGREVISION=	5
TEXLIVE_REV=	18835

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/accfonts
COMMENT=	Utilities to derive new fonts from existing ones
LICENSE=	gnu-gpl-v2

DEPENDS+=	t1utils-[0-9]*:../../fonts/t1utils

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/mkt1font bin/vpl2ovp  bin/vpl2vpl

INSTALLATION_DIRS+=	bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/accfonts/* ${WRKSRC}/bin/
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
