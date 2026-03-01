# $NetBSD: Makefile,v 1.21 2026/03/01 22:24:11 wiz Exp $

DISTNAME=	ascii-3.32
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/ascii/
COMMENT=	ASCII character table program
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

USE_TOOLS=		gmake
MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		ad
SUBST_SED.ad+=		-e "s,asciidoctor,asciidoctor${RUBY_SUFFIX},"
SUBST_STAGE.ad=		pre-build
SUBST_FILES.ad+=	Makefile
SUBST_MESSAGE.ad=	Fixing asciidoctor name.

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
