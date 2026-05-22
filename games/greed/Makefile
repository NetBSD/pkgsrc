# $NetBSD: Makefile,v 1.12 2026/05/22 11:17:09 wiz Exp $

DISTNAME=	greed-5.2
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/greed/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/greed/
COMMENT=	Strategy game: eat as much as possible
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=		${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	${PKGMANDIR}/man6

pre-configure:
	${LN} -s ${PREFIX}/bin/asciidoctor${RUBY_SUFFIX} ${TOOLS_DIR}/bin/asciidoctor

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make greed.6

post-install:
	${INSTALL_DATA} ${WRKSRC}/greed.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "cargo-depends.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
