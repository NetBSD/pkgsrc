# $NetBSD: Makefile,v 1.5 2019/08/11 13:21:01 wiz Exp $

DISTNAME=	dosepsbin
PKGNAME=	tex-${DISTNAME}-1.2
PKGREVISION=	4
TEXLIVE_REV=	29752

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dosepsbin
COMMENT=	Deal with DOS binary EPS files
LICENSE=	artistic

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/dosepsbin

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/dosepsbin/dosepsbin.pl \
		${WRKSRC}/bin/dosepsbin
	${RM} -rf ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
