# $NetBSD: Makefile,v 1.14 2024/03/21 10:24:31 markd Exp $

DISTNAME=	make4ht
PKGNAME=	tex-${DISTNAME}-0.4
TEXLIVE_REV=	70112

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/make4ht
COMMENT=	A build system for tex4ht
LICENSE=	lppl-1.3c

DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex

REPLACE_TEXLUA=	texmf-dist/scripts/make4ht/make4ht

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/make4ht/make4ht ${DESTDIR}${PREFIX}/bin/make4ht

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
