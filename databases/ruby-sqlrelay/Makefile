# $NetBSD: Makefile,v 1.24 2020/08/31 18:07:14 wiz Exp $

COMMENT=		Ruby extension for SQL Relay
PKGREVISION=		15

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
