# $NetBSD: Makefile,v 1.3 2024/02/10 14:42:39 taca Exp $

DISTNAME=	convbkmk
PKGNAME=	tex-${DISTNAME}-0.30
PKGREVISION=	2
TEXLIVE_REV=	49252

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/convbkmk
COMMENT=	Correct platex/uplatex bookmarks in PDF created with hyperref
LICENSE=	mit

INSTALLATION_DIRS+=	bin

REPLACE_RUBY=	texmf-dist/scripts/convbkmk/convbkmk.rb

post-install:
	${LN} -sf ../share/texmf-dist/scripts/convbkmk/convbkmk.rb \
		${DESTDIR}${PREFIX}/bin/convbkmk

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
