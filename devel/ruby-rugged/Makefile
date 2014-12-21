# $NetBSD: Makefile,v 1.4 2014/12/21 02:58:53 obache Exp $

DISTNAME=	rugged-0.21.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

RUBY_VERSION_SUPPORTED=	193 200 21

USE_TOOLS+=	cmake pkg-config

CONFIGURE_ARGS+=	--use-system-libraries

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
