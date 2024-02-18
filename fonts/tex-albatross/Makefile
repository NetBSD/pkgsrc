# $NetBSD: Makefile,v 1.4 2024/02/18 09:44:44 markd Exp $

DISTNAME=	albatross
PKGNAME=	tex-${DISTNAME}-0.5.1
TEXLIVE_REV=	69879

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/albatross
COMMENT=	Find fonts that contain a given glyph
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/albatross/albatross.sh ${DESTDIR}${PREFIX}/bin/albatross

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
