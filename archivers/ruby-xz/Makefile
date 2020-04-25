# $NetBSD: Makefile,v 1.20 2020/04/25 19:56:49 rillig Exp $

DISTNAME=	ruby-xz-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	archivers

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Quintus/ruby-xz
COMMENT=	Ruby bindings for liblzma
LICENSE=	mit

DEPENDS+=	${RUBY_NAME}-fiddle>=${RUBY_VERSION}:../../devel/ruby-fiddle

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
