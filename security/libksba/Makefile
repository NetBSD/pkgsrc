# $NetBSD: Makefile,v 1.19 2009/12/21 18:58:40 joerg Exp $
#

DISTNAME=	libksba-1.0.7
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libksba/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.2

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	YES

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
