# $NetBSD: Makefile,v 1.5 2026/03/04 19:41:48 markd Exp $

DISTNAME=	context-legacy
PKGNAME=	tex-${DISTNAME}-2025.78010
TEXLIVE_REV=	78010

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context
COMMENT=	ConTeXt macro package, MkII

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-ly1-[0-9]*:../../fonts/tex-ly1
DEPENDS+=	tex-manfnt-font-[0-9]*:../../fonts/tex-manfnt-font
DEPENDS+=	tex-mflogo-font-[0-9]*:../../fonts/tex-mflogo-font
DEPENDS+=	tex-mptopdf-[0-9]*:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd

TEX_MAP_FILES+=	original-context-symbol.map

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/context/ruby/*.rb

TEX_FORMATS+=	"cont-en pdftex cont-usr.tex -8bit *cont-en.mkii\\ncont-en xetex cont-usr.tex -8bit *cont-en.mkii\\n"

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/context/stubs/unix/texexec \
	${DESTDIR}${PREFIX}/bin/texexec
	ln -s ${PREFIX}/share/texmf-dist/scripts/context/stubs/unix/texmfstart \
	${DESTDIR}${PREFIX}/bin/texmfstart

.include "../../mk/bsd.pkg.mk"
