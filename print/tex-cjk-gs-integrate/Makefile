# $NetBSD: Makefile,v 1.7 2018/08/22 09:46:15 wiz Exp $

DISTNAME=	cjk-gs-integrate
PKGNAME=	tex-${DISTNAME}-20180306.0
PKGREVISION=	1
TEXLIVE_REV=	46878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cjk-gs-integrate
COMMENT=	Tools to integrate CJK fonts into Ghostscript
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/cjk-gs-integrate

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/cjk-gs-integrate/cjk-gs-integrate.pl \
		${WRKSRC}/bin/cjk-gs-integrate
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
