# $NetBSD: Makefile,v 1.1 2015/05/06 08:51:59 wiz Exp $

DISTNAME=	xskak
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	35945

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xskak
COMMENT=	Extension to the skak package for chess typesetting
LICENSE=	lppl-1.3c

DEPENDS+=	tex-chessboard-[0-9]*:../../print/tex-chessboard
DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss
DEPENDS+=	tex-skak>=1.4:../../print/tex-skak
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
