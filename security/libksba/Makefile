# $NetBSD: Makefile,v 1.4 2004/02/25 15:53:17 minskim Exp $
#

DISTNAME=	libksba-0.9.1
PKGREVISION=	2
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
