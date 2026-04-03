# $NetBSD: Makefile,v 1.6 2026/04/03 05:58:08 markd Exp $

DISTNAME=	hitex
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	77830

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hitex
COMMENT=	TeX extension writing HINT output for on-screen reading
LICENSE=	x11

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"hitex hitex language.def -etex -ltx hitex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf hitex ${DESTDIR}${PREFIX}/bin/hilatex

.include "../../mk/bsd.pkg.mk"
