# $NetBSD: Makefile,v 1.3 2004/01/25 22:29:50 kleink Exp $
#

DISTNAME=	libksba-0.4.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/aegypten/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library (0.4 branch)

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	ksba.info

.include "../../mk/bsd.pkg.mk"
