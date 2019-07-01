# $NetBSD: Makefile,v 1.15 2019/07/01 04:08:02 ryoon Exp $

COMMENT=		Ruby extension for SQL Relay
PKGREVISION=		7

.include "../../databases/sqlrelay/Makefile.common"

CONFIGURE_ARGS+=	ac_cv_prog_RUBY=${RUBY}
CONFIGURE_ARGS+=	--with-ruby-site-arch-dir=${PREFIX}/${RUBY_VENDORARCHLIB}

BUILD_DIRS=		src/api/ruby

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
