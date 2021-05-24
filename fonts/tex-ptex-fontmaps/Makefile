# $NetBSD: Makefile,v 1.12 2021/05/24 19:52:14 wiz Exp $

DISTNAME=	ptex-fontmaps
PKGNAME=	tex-${DISTNAME}-20201227.0
PKGREVISION=	1
TEXLIVE_REV=	57239

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
