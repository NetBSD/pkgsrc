# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:15:11 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		pcre
CATEGORIES+=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for Perl-compatible regular expressions

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-pcre-regex=shared,${BUILDLINK_DIR}

.include "../../devel/pcre/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
