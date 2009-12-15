# $NetBSD: Makefile,v 1.18 2009/12/15 19:27:36 drochner Exp $
#

DISTNAME=	libksba-1.0.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	YES

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
