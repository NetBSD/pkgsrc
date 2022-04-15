# $NetBSD: Makefile,v 1.13 2022/04/15 04:28:55 markd Exp $

DISTNAME=	ptex-fontmaps
PKGNAME=	tex-${DISTNAME}-20210625.0
TEXLIVE_REV=	59711

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex-fontmaps
COMMENT=	Font maps and configuration tools for Japanese/Chinese/Korean fonts with (u)ptex
LICENSE=	public-domain AND gnu-gpl-v3

DEPENDS+=	tex-arphic-ttf-[0-9]*:../../fonts/tex-arphic-ttf
DEPENDS+=	tex-baekmuk-[0-9]*:../../fonts/tex-baekmuk
DEPENDS+=	tex-haranoaji-[0-9]*:../../fonts/tex-haranoaji

USE_TOOLS+=	perl:run

REPLACE_PERL+=	texmf-dist/scripts/ptex-fontmaps/kanji-config-updmap.pl
REPLACE_PERL+=	texmf-dist/scripts/ptex-fontmaps/kanji-fontmap-creator.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
