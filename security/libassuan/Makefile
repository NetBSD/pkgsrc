# $NetBSD: Makefile,v 1.5 2004/12/23 11:40:47 shannonjr Exp $
#

DISTNAME=		libassuan-0.6.9
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/alpha/libassuan/
COMMENT=		The IPC library used by some GnuPG related software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes

INFO_FILES=		assuan.info

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
