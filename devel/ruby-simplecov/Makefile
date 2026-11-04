# $NetBSD: Makefile,v 1.37 2026/11/04 15:02:15 taca Exp $

DISTNAME=	simplecov-1.3.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/colszowka/simplecov
COMMENT=	Code coverage for Ruby
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	if ${TEST} ! -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/simplecov${RUBY_SUFFIX}.1; then \
		${INSTALL_MAN} ${WRKSRC}/man/simplecov.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/simplecov${RUBY_SUFFIX}.1; \
	fi

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
