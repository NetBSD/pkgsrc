# $NetBSD: Makefile,v 1.6 2020/01/18 23:34:54 rillig Exp $

DISTNAME=	tex4ebook
PKGNAME=	tex-${DISTNAME}-0.2c
TEXLIVE_REV=	50512

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tex4ebook
COMMENT=	Convertor from LaTeX to ebook formats
LICENSE=	lppl-1.3c

DEPENDS+=	tex-make4ht-[0-9]*:../../print/tex-make4ht
DEPENDS+=	tex-tex4ebook-doc-[0-9]*:../../print/tex-tex4ebook-doc	# for tidyconf.conf
DEPENDS+=	tex-tex4ht-[0-9]*:../../print/tex-tex4ht
DEPENDS+=	tidy-[0-9]*:../../www/tidy

USE_TOOLS+=	zip:run

REPLACE_TEXLUA=	texmf-dist/scripts/tex4ebook/tex4ebook

INSTALLATION_DIRS+=	bin

post-install:
	ln -s ${PREFIX}/share/texmf-dist/scripts/tex4ebook/tex4ebook ${DESTDIR}${PREFIX}/bin/tex4ebook

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
