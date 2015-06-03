# $NetBSD: Makefile,v 1.6 2015/06/03 13:22:02 taca Exp $

DISTNAME=	rugged-0.22.2
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
