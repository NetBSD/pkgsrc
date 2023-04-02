# $NetBSD: Makefile,v 1.3 2023/04/02 11:00:58 markd Exp $

DISTNAME=	albatross
PKGNAME=	tex-${DISTNAME}-0.5.0
TEXLIVE_REV=	65647

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/albatross
COMMENT=	Find fonts that contain a given glyph
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/albatross/albatross.sh ${DESTDIR}${PREFIX}/bin/albatross

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
