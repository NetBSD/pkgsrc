# $NetBSD: Makefile,v 1.14 2013/11/17 17:12:19 minskim Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	30947

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
CONFLICTS+=	texlive-tetex<=2011nb2
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/web2c/mktex.opt \
				texmf-dist/web2c/mktex[a-z]* \
				texmf-dist/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
