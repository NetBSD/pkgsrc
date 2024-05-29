# $NetBSD: Makefile,v 1.37 2024/05/29 16:31:54 adam Exp $

COMMENT=	Ruby extension for SQL Relay
PKGREVISION=	5

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--with-ruby-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}
CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
