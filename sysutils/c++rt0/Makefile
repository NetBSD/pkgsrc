#	$NetBSD: Makefile,v 1.1.1.1 2000/10/04 15:13:03 hubertf Exp $
#

DISTNAME=	c++rt0-1.0
DISTFILES=	c++rt0.o.PIC c++rt0.o.pic README
DIST_SUBDIR=	c++rt0
MASTER_SITES+=	ftp://ftp.netbsd.org/pub/NetBSD/arch/sparc/c++rt0/

CATEGORIES=	sysutils
MAINTAINER=	hubertf@netbsd.org

ONLY_FOR_PLATFORM=	NetBSD-1.4*-sparc

EXTRACT_ONLY=	# empty
NO_PATCH=	yes

do-build:
	@${ECHO} Nothing to do.

do-install:
	${INSTALL_DATA_DIR}	${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/c++rt0.o.pic ${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/c++rt0.o.PIC ${PREFIX}/lib/c++rt0
	${INSTALL_DATA}	${_DISTDIR}/README	${PREFIX}/lib/c++rt0
	${MV} /usr/lib/c++rt0.o /usr/lib/c++rt0.o.unPKGd
	${INSTALL} -c -m 444 -o root -g wheel ${PREFIX}/lib/c++rt0/c++rt0.o.PIC /usr/lib/c++rt0.o

.include "../../mk/bsd.pkg.mk"
