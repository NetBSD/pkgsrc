# $NetBSD: Makefile,v 1.4 2002/02/28 06:17:34 jlam Exp $

MODNAME=		pcre
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for Perl-compatible regular expressions

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-pcre-regex=shared,${BUILDLINK_DIR}

.include "../../devel/pcre/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
