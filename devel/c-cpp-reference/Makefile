# $NetBSD: Makefile,v 1.7 2003/07/30 15:56:08 markd Exp $
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
USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
