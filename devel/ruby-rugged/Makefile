# $NetBSD: Makefile,v 1.8 2015/10/12 05:55:27 taca Exp $

DISTNAME=	rugged-0.23.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

USE_TOOLS+=	cmake pkg-config

CONFIGURE_ARGS+=	--use-system-libraries

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
