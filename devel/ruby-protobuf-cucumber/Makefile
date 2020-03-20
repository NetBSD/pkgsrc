# $NetBSD: Makefile,v 1.3 2020/03/20 15:09:58 taca Exp $

DISTNAME=	protobuf-cucumber-3.10.8
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/localshred/protobuf
COMMENT=	Google Protocol Buffers serialization and RPC implementation
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-middleware>=0:../../devel/ruby-middleware
DEPENDS+=	${RUBY_PKGPREFIX}-thor>=0:../../devel/ruby-thor
DEPENDS+=	${RUBY_PKGPREFIX}-thread_safe>=0:../../misc/ruby-thread_safe

RUBY_RAILS_ACCEPTED=	# defined
USE_LANGUAGES=		# none
RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
