# $NetBSD: Makefile,v 1.28 2024/03/21 09:21:13 markd Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70681

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kpathsea
COMMENT=	Translation tables for TeX
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
CONFLICTS+=	texlive-tetex<=2011nb2
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	texmf-dist/web2c/mktex.opt texmf-dist/web2c/mktexdir \
			texmf-dist/web2c/mktexnam texmf-dist/web2c/mktexnam.opt \
			texmf-dist/web2c/mktexupd
SUBST_SED.paths=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
