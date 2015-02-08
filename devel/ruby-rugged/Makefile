# $NetBSD: Makefile,v 1.5 2015/02/08 07:21:28 taca Exp $

DISTNAME=	rugged-0.21.4
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
