# $NetBSD: Makefile,v 1.1.1.1 2011/11/06 08:37:32 minskim Exp $

DISTNAME=	texlive.infra
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	24419

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic TeX Live infrastructure

USE_TOOLS+=	perl:run

TEXLIVE_IGNORE_PATTERNS=	texmf/scripts

INSTALLATION_DIRS+=	${PERL5_SUB_INSTALLVENDORLIB}/TeXLive
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../lang/perl5/dirs.mk"
.include "../../print/texlive/package.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm \
		${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/TeXLive/

.include "../../mk/bsd.pkg.mk"
