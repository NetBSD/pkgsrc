# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:32 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pcre
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for Perl-compatible regular expressions

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-pcre-regex=shared,${BUILDLINK_DIR}

.include "../../devel/pcre/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
