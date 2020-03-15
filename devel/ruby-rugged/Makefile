# $NetBSD: Makefile,v 1.22 2020/03/15 17:05:59 taca Exp $

DISTNAME=	rugged-0.99.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

USE_TOOLS+=	cmake pkg-config

CONFIGURE_ARGS+=	--use-system-libraries

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
