# $NetBSD: Makefile,v 1.2 2024/03/21 11:38:01 markd Exp $

DISTNAME=	context-legacy
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70191

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-legacy
COMMENT=	Legacy context components

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
DEPENDS+=	tex-mptopdf-[0-9]*:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex

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
