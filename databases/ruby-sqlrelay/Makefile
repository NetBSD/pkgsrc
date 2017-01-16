# $NetBSD: Makefile,v 1.8 2017/01/16 13:15:22 fhajny Exp $

COMMENT=		Ruby extension for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
