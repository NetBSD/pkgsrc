# $NetBSD: Makefile,v 1.1.1.1 1999/07/12 02:36:06 hubertf Exp $
#

DISTNAME=	compupic-current-i386-Linux
PKGNAME=	CompuPic-4.6.1005
CATEGORIES=	graphics
MASTER_SITES=	http://linux.compupic.com/files/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://linux.compupic.com/

DEPENDS+=	suse_linux-6.1:../../emulators/suse_linux

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

LICENSE=	fee-based-commercial-use
WRKSRC=		${WRKDIR}/compupic-4.6.1005-i386-Linux

NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_PACKAGE=	"Commercial product, purcase at http://www.photodex.com/ordering/order.html"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/compupic
	${GTAR} plxCf ${PREFIX}/libexec/compupic ${WRKSRC}/compupic.tar
	${MV} ${PREFIX}/libexec/compupic/compupic.1 ${PREFIX}/man/man1
	${LN} -sf ../libexec/compupic/compupic ${PREFIX}/bin/compupic

.include "../../mk/bsd.pkg.mk"
