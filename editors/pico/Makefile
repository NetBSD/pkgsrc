# $NetBSD: Makefile,v 1.34 2002/12/14 10:28:41 tron Exp $

DISTNAME=	pine4.51
PKGNAME=	pico-4.4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Text editor (ships with Pine), and Pine's text editing lib

LICENSE=	pine-license

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDNAME= so5
.elif ${OPSYS} == "Darwin"
BUILDNAME= osx
.else
BUILDNAME= neb
.endif

MAKE_ENV+=	_STRIPFLAG_INSTALL=	# debug...

do-build:
	cd ${WRKSRC} && \
	./build ${BUILDNAME} CC="${PKGLIBTOOL} ${BUILDLINK_CC}" \
	  PREFIX=${PREFIX}

do-install:
	${PKGLIBTOOL} --mode=install ${INSTALL_DATA} \
	  ${WRKSRC}/pico/libpico.la ${PREFIX}/lib
	${PKGLIBTOOL} --mode=install ${INSTALL_PROGRAM} \
	  ${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/include/pico
	cd ${WRKSRC}/pico && \
	${INSTALL_DATA} *.h ${PREFIX}/include/pico

.include "../../mk/bsd.pkg.mk"
