# $NetBSD: Makefile,v 1.18 2000/03/09 10:36:47 tron Exp $
#

DISTNAME=	teTeX-1.0.7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	teTeX-bin>=1.0.7:../teTeX-bin
DEPENDS+=	teTeX-sharesrc>=1.0.1:../teTeX-sharesrc

USE_X11=        yes
EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} ${PKGNAME} \
	  POST-INSTALL

.include "../../mk/bsd.pkg.mk"
