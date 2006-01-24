# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:01 wiz Exp $
#

DISTNAME=	c_cpp_reference-2.0.2
PKGNAME=	${DISTNAME:S/_/-/g}
PKGREVISION=	6
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=3.1.0:../../devel/kdevelop-base

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g'			\
	< ${FILESDIR}/c_reference.toc > ${WRKDIR}/c_reference.toc
	${SED} -e 's,@PREFIX@,${PREFIX},g'			\
	< ${FILESDIR}/c++_reference.toc > ${WRKDIR}/c++_reference.toc

post-install:
	${INSTALL_DATA} ${WRKDIR}/c_reference.toc ${PREFIX}/share/kde/apps/kdevdocumentation/tocs/c_reference.toc
	${INSTALL_DATA} ${WRKDIR}/c++_reference.toc ${PREFIX}/share/kde/apps/kdevdocumentation/tocs/c++_reference.toc

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
