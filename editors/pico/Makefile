# $NetBSD: Makefile,v 1.18 1999/12/02 17:01:05 bouyer Exp $
#

DISTNAME=	pine4.21
PKGNAME=	pico-3.7
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.washington.edu/pine/

USE_LIBTOOL=	yes

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
.if ${OPSYS} == "SunOS"
BUILDNAME= so5
.else
BUILDNAME= neb
.endif
