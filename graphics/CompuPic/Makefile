# $NetBSD: Makefile,v 1.11 2001/05/12 16:17:45 wiz Exp $
#

DISTNAME=	compupic-5.1.1063-i386-netbsd
PKGNAME=	CompuPic-5.1.1063
CATEGORIES=	graphics
MASTER_SITES=	http://www.photodex.com/files/unix/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://beta.compupic.com/
COMMENT=	Tool for managing graphics and multimedia files

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=	fee-based-commercial-use

NO_CONFIGURE=	YES
NO_BUILD=	YES
RESTRICTED=	"Commercial product, purchase at http://www.photodex.com/ordering/order.html"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
EXTRACT_CMD=	${TRUE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/compupic
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/compupic
	${GTAR} plzxCf ${PREFIX}/libexec/ ${_DISTDIR}/${DISTFILES}
	${MV} ${PREFIX}/libexec/compupic/compupic.1 ${PREFIX}/man/man1
	${MV} ${PREFIX}/libexec/compupic/LICENSE ${PREFIX}/share/doc/compupic
	${MV} ${PREFIX}/libexec/compupic/README ${PREFIX}/share/doc/compupic
	${MV} ${PREFIX}/libexec/compupic/order.txt ${PREFIX}/share/doc/compupic
# simulate symlink -- relative symlink (to which it `ln -s' automatically
# gets fixed) -- doesn't work, since compupic doesn't find its support files
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/compupic
	${ECHO} "${PREFIX}/libexec/compupic/compupic" >> ${PREFIX}/bin/compupic
	${CHMOD} 755 ${PREFIX}/bin/compupic

.include "../../mk/bsd.pkg.mk"
