# $NetBSD: Makefile,v 1.7 2026/03/01 07:34:14 taca Exp $

DISTNAME=		mustache-1.1.2
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
