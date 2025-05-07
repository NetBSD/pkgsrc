# $NetBSD: Makefile,v 1.24 2025/05/07 11:44:18 markd Exp $

DISTNAME=	hyphen-base
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74125

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX hyphenation patterns for English
LICENSE=	lppl-1.3c

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/tex/generic/config
CONF_FILES+=	${PREFIX}/share/texmf-dist/tex/generic/config/language.dat \
		${PKG_SYSCONFDIR}/tex/generic/config/language.dat
CONF_FILES+=	${PREFIX}/share/texmf-dist/tex/generic/config/language.dat.lua \
		${PKG_SYSCONFDIR}/tex/generic/config/language.dat.lua
CONF_FILES+=	${PREFIX}/share/texmf-dist/tex/generic/config/language.def \
		${PKG_SYSCONFDIR}/tex/generic/config/language.def

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
