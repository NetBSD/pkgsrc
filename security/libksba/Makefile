# $NetBSD: Makefile,v 1.2 2004/01/25 22:29:50 kleink Exp $
#

DISTNAME=	libksba-0.9.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libksba/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	ksba.info

.include "../../security/libgcrypt/buildlink2.mk"
.include "../../security/libgpg-error/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
