# $NetBSD: Makefile,v 1.16 1999/08/18 07:48:31 tron Exp $
#

DISTNAME=	teTeX-1.0.6
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	teTeX-bin-1.0.6:../teTeX-bin
DEPENDS+=	teTeX-sharesrc-1.0:../teTeX-sharesrc

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
