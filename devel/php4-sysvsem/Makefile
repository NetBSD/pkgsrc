# $NetBSD: Makefile,v 1.5 2002/02/28 06:17:49 jlam Exp $

MODNAME=		sysvsem
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SysV semaphore support

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
