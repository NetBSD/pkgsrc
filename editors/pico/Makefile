# $NetBSD: Makefile,v 1.57 2004/10/03 00:14:39 tv Exp $

DISTNAME=	pine4.61
PKGNAME=	pico-4.8
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Text editor (ships with Pine), and Pine's text editing lib

LICENSE=	pine-license

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDNAME=	so5
.elif ${OPSYS} == "Darwin"
BUILDNAME=	osx
LIBS+=		-lcurses
.elif ${OPSYS} == "Linux"
BUILDNAME=	lnx
.else
BUILDNAME=	neb
.endif

MAKE_ENV+=	_STRIPFLAG_INSTALL=	# debug...

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build ${BUILDNAME} \
		CC="${LIBTOOL} ${CC}" \
		PREFIX=${PREFIX} OPTIMIZE="${CFLAGS}" \
		EXTRALDFLAGS="${LIBS}"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/pico/libpico.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/include/pico
	cd ${WRKSRC}/pico && ${INSTALL_DATA} *.h ${PREFIX}/include/pico

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
