# $NetBSD: Makefile,v 1.8 2026/09/06 14:27:37 taca Exp $

DISTNAME=		mustache-1.1.3
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		devel

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://mustache.github.io/
COMMENT=		Logic-less Ruby templates
LICENSE=		mit

RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
