# $NetBSD: Makefile,v 1.5 2004/01/13 18:59:35 jdolecek Exp $

MODNAME=		ftp
CATEGORIES+=		net
PKGREVISION=		1
COMMENT=		PHP4 extension for FTP access

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
