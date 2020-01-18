# $NetBSD: Makefile,v 1.8 2020/01/18 23:31:49 rillig Exp $

DISTNAME=	ptex-fontmaps
PKGNAME=	tex-${DISTNAME}-20190506.0
PKGREVISION=	1
TEXLIVE_REV=	51023

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex-fontmaps
COMMENT=	Font maps and configuration tools for Japanese/Chinese/Korean fonts with (u)ptex
LICENSE=	gnu-gpl-v3 AND public-domain

DEPENDS+=	tex-arphic-ttf-[0-9]*:../../fonts/tex-arphic-ttf
DEPENDS+=	tex-baekmuk-[0-9]*:../../fonts/tex-baekmuk
DEPENDS+=	tex-ipaex-[0-9]*:../../fonts/tex-ipaex

USE_TOOLS+=	perl:run

REPLACE_PERL+=	texmf-dist/scripts/ptex-fontmaps/kanji-config-updmap.pl
REPLACE_PERL+=	texmf-dist/scripts/ptex-fontmaps/kanji-fontmap-creator.pl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
