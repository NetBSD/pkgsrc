# $NetBSD: Makefile,v 1.5 2001/02/17 17:42:11 wiz Exp $
#

DISTNAME=	c++rt0-1.0
CATEGORIES=	sysutils
MASTER_SITES+=	ftp://ftp.netbsd.org/pub/NetBSD/arch/sparc/c++rt0/
DISTFILES=	c++rt0.o.PIC c++rt0.o.pic README

MAINTAINER=	hubertf@netbsd.org
COMMENT=	1.4.x/sparc PIC c++rt0.o file

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
