# $NetBSD: Makefile,v 1.10 2026/05/12 18:06:06 wiz Exp $

DISTNAME=	greed-5.0
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/greed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/greed/
COMMENT=	Strategy game: eat as much as possible
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

USE_TOOLS+=		gmake

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		SFILE=${PREFIX}/share/games/greed.hs

pre-configure:
	${LN} -s ${PREFIX}/bin/asciidoctor${RUBY_SUFFIX} ${TOOLS_DIR}/bin/asciidoctor

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/rust/rust.mk"
.include "../../mk/bsd.pkg.mk"
