# $NetBSD: Makefile,v 1.1.1.1 2011/01/23 01:26:46 minskim Exp $

DISTNAME=	ptex
PKGNAME=	tex-${DISTNAME}-3.1.9
TEXLIVE_REV=	21070

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX system for publishing in Japanese

CONFLICTS+=	ja-ptex-bin-[0-9]*
DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	web2c>=2010nb5:../../print/web2c

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/tex/ptexgeneric/config
CONF_FILES+=	${PREFIX}/share/texmf-dist/tex/ptexgeneric/config/language.ptx \
		${PKG_SYSCONFDIR}/tex/ptexgeneric/config/language.ptx

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"ptex ptex - ptex.ini\\nplatex ptex language.ptx platex.ini\\n"
TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf ptex ${DESTDIR}${PREFIX}/bin/platex

.include "../../mk/bsd.pkg.mk"
