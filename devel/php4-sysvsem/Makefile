# $NetBSD: Makefile,v 1.4 2001/12/03 08:31:01 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sysvsem
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for SysV semaphore support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.pkg.mk"
