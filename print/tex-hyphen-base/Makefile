# $NetBSD: Makefile,v 1.5 2010/05/02 16:34:40 minskim Exp $
# TeX Live Revision 18069

DISTNAME=	hyphen-base
PKGNAME=	tex-${DISTNAME}-2009.17785
DIST_SUBDIR=	${PKGNAME_NOREV:S/17785/18069/}

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX hyphenation patterns for English

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/tex/generic/config
CONF_FILES+=	${PREFIX}/share/texmf/tex/generic/config/language.dat \
		${PKG_SYSCONFDIR}/tex/generic/config/language.dat
CONF_FILES+=	${PREFIX}/share/texmf/tex/generic/config/language.def \
		${PKG_SYSCONFDIR}/tex/generic/config/language.def

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
