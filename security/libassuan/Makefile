# $NetBSD: Makefile,v 1.9 2006/03/31 23:56:29 jlam Exp $
#

DISTNAME=		libassuan-0.6.10
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
