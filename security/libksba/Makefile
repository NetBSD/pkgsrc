# $NetBSD: Makefile,v 1.6 2004/10/03 00:18:09 tv Exp $
#

DISTNAME=	libksba-0.9.4
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libksba/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	ksba.info

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
