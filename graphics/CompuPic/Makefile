# $NetBSD: Makefile,v 1.6 2000/04/02 02:56:26 wiz Exp $
#

DISTNAME=	compupic-5.0.1033-i386-netbsd
PKGNAME=	CompuPic-5.0.1033
CATEGORIES=	graphics
MASTER_SITES=	http://unix.compupic.com/files/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://unix.compupic.com/

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	fee-based-commercial-use

NO_CONFIGURE=	YES
NO_BUILD=	YES
RESTRICTED=	"Commercial product, purchase at http://www.photodex.com/ordering/order.html"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
EXTRACT_CMD=	# empty

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/compupic
	${GTAR} plzxCf ${PREFIX}/libexec/ ${_DISTDIR}/${DISTFILES}
	${MV} ${PREFIX}/libexec/compupic/compupic.1 ${PREFIX}/man/man1
# simulate symlink -- relative symlink (to which it `ln -s' automatically
# gets fixed) -- doesn't work, since compupic doesn't find its support files
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/compupic
	${ECHO} "${PREFIX}/libexec/compupic/compupic" >> ${PREFIX}/bin/compupic
	${CHMOD} 755 ${PREFIX}/bin/compupic

.include "../../mk/bsd.pkg.mk"
