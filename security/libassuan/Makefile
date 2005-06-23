# $NetBSD: Makefile,v 1.7 2005/06/23 09:21:18 shannonjr Exp $
#

DISTNAME=		libassuan-0.6.10
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

INFO_FILES=		assuan.info

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
