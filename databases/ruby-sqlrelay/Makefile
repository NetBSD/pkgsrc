# $NetBSD: Makefile,v 1.23 2020/05/22 10:56:01 adam Exp $

COMMENT=		Ruby extension for SQL Relay
PKGREVISION=		14

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
