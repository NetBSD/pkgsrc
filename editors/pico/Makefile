# $NetBSD: Makefile,v 1.28 2001/12/15 08:31:08 martti Exp $
#

DISTNAME=	pine4.43
PKGNAME=	pico-4.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/pine/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Text editor (ships with Pine), and Pine's text editing lib

LICENSE=	pine-license

USE_LIBTOOL=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDNAME= so5
.else
BUILDNAME= neb
.endif

MAKE_ENV+=	STRIPFLAG=	# debug...

do-build:
	cd ${WRKSRC} && ./build ${BUILDNAME} CC="${LIBTOOL} ${CC}" \
	    PREFIX=${PREFIX}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/pico/libpico.la ${PREFIX}/lib/
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin/
	${INSTALL_MAN}     ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/
	${INSTALL_MAN}     ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/include/pico
	cd ${WRKSRC}/pico && \
		${INSTALL_DATA} ebind.h edef.h efunc.h estruct.h headers.h \
			msmenu.h os.h pico.h resource.h \
			${PREFIX}/include/pico/

.include "../../mk/bsd.pkg.mk"
