# $NetBSD: Makefile,v 1.23 2001/10/24 00:28:47 kei Exp $
#

DISTNAME=	teTeX-1.0.7nb1
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	teTeX-bin>=1.0.7nb1:../teTeX-bin
DEPENDS+=	teTeX-sharesrc>=1.0.1nb1:../teTeX-sharesrc

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
