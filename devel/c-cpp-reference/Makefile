# $NetBSD: Makefile,v 1.2 2001/12/17 08:26:43 skrll Exp $
#

DISTNAME=	c_cpp_reference-2.0.1
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=2.0:../kdevelop-base

USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
