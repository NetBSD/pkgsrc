# $NetBSD: Makefile,v 1.1 2021/02/14 02:14:00 markd Exp $

DISTNAME=	albatross
PKGNAME=	tex-${DISTNAME}-0.3.0
TEXLIVE_REV=	57416

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/albatross
COMMENT=	Find fonts that contain a given glyph
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/albatross/albatross.sh ${DESTDIR}${PREFIX}/bin/albatross

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
