# $NetBSD: Makefile,v 1.8 2026/02/26 13:34:44 wiz Exp $

DISTNAME=		greed-4.4
CATEGORIES=		games
MASTER_SITES=		http://www.catb.org/~esr/greed/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.catb.org/~esr/greed/
COMMENT=		Strategy game: eat as much as possible
LICENSE=		2-clause-bsd

TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

USE_TOOLS+=		gmake

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		SFILE=${PREFIX}/share/games/greed.hs

SUBST_CLASSES+=		ad
SUBST_SED.ad+=		-e "s,asciidoctor,asciidoctor${RUBY_SUFFIX},"
SUBST_STAGE.ad=		pre-build
SUBST_FILES.ad+=	Makefile
SUBST_MESSAGE.ad=	Fixing asciidoctor name.

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
