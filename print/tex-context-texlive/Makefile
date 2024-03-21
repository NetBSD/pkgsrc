# $NetBSD: Makefile,v 1.4 2024/03/21 12:09:19 markd Exp $

DISTNAME=	context-texlive
PKGNAME=	tex-${DISTNAME}-2024
TEXLIVE_REV=	70437

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	TL-specific helpers for ConTeXt (caches, papersize)

INSTALLATION_DIRS+=	bin

post-install:
	${LN} -s ${PREFIX}/share/texmf-dist/scripts/context-texlive/stubs-mkiv/unix/contextjit ${DESTDIR}${PREFIX}/bin/contextjit
	${LN} -s ${PREFIX}/share/texmf-dist/scripts/context-texlive/stubs-mkiv/unix/luatools ${DESTDIR}${PREFIX}/bin/luatools
	${LN} -s ${PREFIX}/share/texmf-dist/scripts/context-texlive/stubs-mkiv/unix/mtxrunjit ${DESTDIR}${PREFIX}/bin/mtxrunjit

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
