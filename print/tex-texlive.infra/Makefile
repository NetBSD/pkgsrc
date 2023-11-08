# $NetBSD: Makefile,v 1.33 2023/11/08 09:00:45 markd Exp $

DISTNAME=	texlive.infra
PKGNAME=	tex-${DISTNAME}-2023
PKGREVISION=	1
TEXLIVE_REV=	66512

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Basic TeX Live infrastructure
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

INSTALLATION_DIRS+=	${PERL5_SUB_INSTALLVENDORLIB}/TeXLive
INSTALLATION_DIRS+=	share/tlpkg
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	tlpkg/TeXLive/TLPaper.pm tlpkg/TeXLive/TLUtils.pm
SUBST_SED.paths=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'

.include "../../print/texlive/package.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/tlpkg/TeXLive/*.pm \
		${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/TeXLive/
	${TOUCH} ${WRKDIR}/texlive.tlpdb
	${INSTALL_DATA} ${WRKDIR}/texlive.tlpdb ${DESTDIR}${PREFIX}/share/tlpkg/

.include "../../mk/bsd.pkg.mk"
