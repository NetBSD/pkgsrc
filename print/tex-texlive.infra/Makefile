# $NetBSD: Makefile,v 1.4 2012/07/24 09:24:22 jperkin Exp $

DISTNAME=	texlive.infra
PKGNAME=	tex-${DISTNAME}-2012
PKGREVISION=	1
TEXLIVE_REV=	26923

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic TeX Live infrastructure

USE_TOOLS+=	perl:run

TEXLIVE_IGNORE_PATTERNS=	texmf/scripts

INSTALLATION_DIRS+=	${PERL5_SUB_INSTALLVENDORLIB}/TeXLive
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	tlpkg/TeXLive/TLPaper.pm tlpkg/TeXLive/TLUtils.pm
SUBST_SED.paths=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'

.include "../../print/texlive/package.mk"
.include "../../lang/perl5/dirs.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm \
		${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/TeXLive/

.include "../../mk/bsd.pkg.mk"
