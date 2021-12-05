# $NetBSD: Makefile,v 1.22 2021/12/05 15:26:13 taca Exp $

DISTNAME=	ruby-xz-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/win93/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	${RUBY_NAME}-fiddle>=${RUBY_VERSION}:../../devel/ruby-fiddle

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
