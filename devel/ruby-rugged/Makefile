# $NetBSD: Makefile,v 1.17 2019/02/24 10:16:02 wiz Exp $

DISTNAME=	rugged-0.27.7
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/rugged
COMMENT=	Ruby bindings to libgit2
LICENSE=	mit

USE_TOOLS+=	cmake pkg-config

CONFIGURE_ARGS+=	--use-system-libraries

# require libgit2 0.27.5 or later.
BUILDLINK_API_DEPENDS.libgit2+=	libgit2>=0.27.5

.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
