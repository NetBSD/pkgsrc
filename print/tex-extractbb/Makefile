# $NetBSD: Makefile,v 1.2 2025/06/12 09:05:01 wiz Exp $

DISTNAME=	extractbb
PKGNAME=	tex-${DISTNAME}-1.1.0
TEXLIVE_REV=	73916

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/extractbb
COMMENT=	Reimplementation of extractbb, written in Lua
LICENSE=	mpl-2.0 AND cc-by-sa-v4.0

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

REPLACE_TEXLUA=	bin/extractbb

INSTALLATION_DIRS+=	bin

CONFLICTS+=	dvipdfmx<20250205

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/extractbb/extractbb.lua ${WRKSRC}/bin/extractbb

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
