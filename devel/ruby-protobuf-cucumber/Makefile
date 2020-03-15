# $NetBSD: Makefile,v 1.2 2020/03/15 17:21:21 taca Exp $

DISTNAME=	protobuf-cucumber-3.10.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/localshred/protobuf
COMMENT=	Google Protocol Buffers serialization and RPC implementation
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-middleware>=0:../../devel/ruby-middleware
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0:../../misc/ruby-thread_safe

RUBY_RAILS_ACCEPTED=	# yes
USE_LANGUAGES=		# none
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
