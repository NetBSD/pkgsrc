# $NetBSD: Makefile,v 1.6 2003/06/29 14:29:34 grant Exp $

MODNAME=		pcre
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for Perl-compatible regular expressions

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-pcre-regex=shared,${BUILDLINK_PREFIX.pcre}

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
