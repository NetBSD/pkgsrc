# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:01 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pcre
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for Perl-compatible regular expressions

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-pcre-regex=shared,${BUILDLINK_DIR}

.include "../../devel/pcre/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
