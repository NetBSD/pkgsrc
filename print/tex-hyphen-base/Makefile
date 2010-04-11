# $NetBSD: Makefile,v 1.4 2010/04/11 21:56:11 minskim Exp $
# TeX Live Revision 17785

DISTNAME=	hyphen-base
PKGNAME=	tex-${DISTNAME}-2009.17785

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
