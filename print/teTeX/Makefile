# $NetBSD: Makefile,v 1.27 2002/09/21 01:53:37 jlam Exp $
#

DISTNAME=	teTeX-1.0.7
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems

DEPENDS+=	teTeX-bin>=1.0.7nb2:../teTeX-bin
DEPENDS+=	teTeX-sharesrc>=1.0.1nb1:../teTeX-sharesrc
DEPENDS+=	texi2html>=1.52:../../textproc/texi2html

USE_BUILDLINK2=	yes
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
