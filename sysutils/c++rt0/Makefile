# $NetBSD: Makefile,v 1.4 2000/10/21 22:56:47 wiz Exp $
#

DISTNAME=	c++rt0-1.0
CATEGORIES=	sysutils
MASTER_SITES+=	ftp://ftp.netbsd.org/pub/NetBSD/arch/sparc/c++rt0/
DISTFILES=	c++rt0.o.PIC c++rt0.o.pic README

MAINTAINER=	hubertf@netbsd.org

DIST_SUBDIR=	c++rt0
ONLY_FOR_PLATFORM=	NetBSD-1.4-sparc NetBSD-1.4.[12]-sparc

EXTRACT_ONLY=	# empty
NO_PATCH=	yes

do-build:
	@${ECHO} Nothing to do.

do-install:
	${INSTALL_DATA_DIR}	${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/c++rt0.o.pic ${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/c++rt0.o.PIC ${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/README	${PREFIX}/lib/c++rt0

.include "../../mk/bsd.pkg.mk"
