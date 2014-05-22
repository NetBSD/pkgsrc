# $NetBSD: Makefile,v 1.1 2014/05/22 12:50:47 fhajny Exp $

COMMENT=		Ruby extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}
CONFIGURE_ARGS+=	--with-ruby-site-lib-dir=${PREFIX}/${RUBY_VENDORLIB}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
