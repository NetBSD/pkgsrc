# $NetBSD: Makefile,v 1.8 2004/12/03 21:58:54 shannonjr Exp $
#

DISTNAME=	libksba-0.9.10
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/libksba/

MAINTAINER=	shannonjr@NetBSD.org
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
