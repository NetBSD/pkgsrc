# $NetBSD: Makefile,v 1.4 2004/04/12 20:32:43 snj Exp $
#

DISTNAME=	libksba-0.4.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/aegypten/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://www.g10code.com/p-libksba.html
COMMENT=	X.509 library (0.4 branch)

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	ksba.info

.include "../../mk/bsd.pkg.mk"
