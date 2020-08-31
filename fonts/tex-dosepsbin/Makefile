# $NetBSD: Makefile,v 1.8 2020/08/31 18:09:32 wiz Exp $

DISTNAME=	dosepsbin
PKGNAME=	tex-${DISTNAME}-1.2
PKGREVISION=	5
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
