# $NetBSD: Makefile,v 1.9 2021/05/24 19:52:14 wiz Exp $

DISTNAME=	dosepsbin
PKGNAME=	tex-${DISTNAME}-1.2
PKGREVISION=	6
TEXLIVE_REV=	29752

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dosepsbin
COMMENT=	Deal with DOS binary EPS files
LICENSE=	artistic

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/dosepsbin

INSTALLATION_DIRS+=	bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/dosepsbin/dosepsbin.pl \
		${WRKSRC}/bin/dosepsbin
	${RM} -rf ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
