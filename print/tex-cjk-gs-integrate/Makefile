# $NetBSD: Makefile,v 1.11 2020/01/18 23:33:47 rillig Exp $

DISTNAME=	cjk-gs-integrate
PKGNAME=	tex-${DISTNAME}-20190303.0
PKGREVISION=	1
TEXLIVE_REV=	50214

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk-gs-integrate
COMMENT=	Tools to integrate CJK fonts into Ghostscript
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/cjk-gs-integrate

INSTALLATION_DIRS+=	bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/cjk-gs-integrate/cjk-gs-integrate.pl \
		${WRKSRC}/bin/cjk-gs-integrate
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
