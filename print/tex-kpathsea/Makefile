# $NetBSD: Makefile,v 1.13 2012/10/14 21:21:34 minskim Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2012
PKGREVISION=	1
TEXLIVE_REV=	27341

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
CONFLICTS+=	texlive-tetex<=2011nb2
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
