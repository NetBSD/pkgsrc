# $NetBSD: Makefile,v 1.13 2018/06/06 04:46:05 taca Exp $

DISTNAME=	rugged-0.27.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

USE_TOOLS+=	cmake pkg-config

CONFIGURE_ARGS+=	--use-system-libraries

# require libgit2 0.27.0 or later.
BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.27.0

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
