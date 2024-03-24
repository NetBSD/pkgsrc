# $NetBSD: Makefile,v 1.4 2024/03/24 10:41:56 markd Exp $

DISTNAME=	hitex
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70015

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hitex
COMMENT=	TeX extension writing HINT output for on-screen reading
LICENSE=	x11

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	web2c>=2022:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=	"hilatex hitex language.dat -etex -ltx hilatex.ini\\nhitex hitex language.def -etex -ltx hitex.ini\\n"

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf hitex ${DESTDIR}${PREFIX}/bin/hilatex

.include "../../mk/bsd.pkg.mk"
