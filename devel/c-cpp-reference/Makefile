# $NetBSD: Makefile,v 1.8 2004/01/22 08:24:28 grant Exp $
#

DISTNAME=	c_cpp_reference-2.0.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=2.1.1:../kdevelop-base

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
