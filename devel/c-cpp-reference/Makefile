# $NetBSD: Makefile,v 1.9 2004/02/15 11:59:04 markd Exp $
#

DISTNAME=	c_cpp_reference-2.0.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=3.0.0:../../devel/kdevelop-base

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g'			\
	< ${FILESDIR}/c_reference.toc > ${WRKDIR}/c_reference.toc
	${SED} -e 's,@PREFIX@,${PREFIX},g'			\
	< ${FILESDIR}/c++_reference.toc > ${WRKDIR}/c++_reference.toc

post-install:
	${INSTALL_DATA} ${WRKDIR}/c_reference.toc ${PREFIX}/share/kde/apps/kdevdoctreeview/tocs/c_reference.toc
	${INSTALL_DATA} ${WRKDIR}/c++_reference.toc ${PREFIX}/share/kde/apps/kdevdoctreeview/tocs/c++_reference.toc

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
