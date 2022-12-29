# $NetBSD: Makefile,v 1.5 2022/12/29 16:23:51 taca Exp $

DISTNAME=		mustache-1.1.1
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		2
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
