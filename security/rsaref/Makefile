# $NetBSD: Makefile,v 1.16 1999/12/14 22:36:47 abs Exp $
#

DISTNAME=		rsaref
PKGNAME=		rsaref-2.0p3
WRKSRC=			${WRKDIR}/install
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.spinnaker.com/pub/crypt/rsaref/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tv@netbsd.org

RESTRICTED=		"Cryptographic source usable only within the USA"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		yes # requires options to be set in order to use
LICENSE=		no-commercial-use

USE_LIBTOOL=		yes
MAKEFILE=		unix/makefile
ALL_TARGET=		librsaref.la

fetch-depends:
	@if [ "X${USA_RESIDENT}" != XYES ]; then	\
		${ECHO} "This package is legal for use only within the United States."; \
		${ECHO} "You must set the variable USA_RESIDENT to YES to enable"; \
		${ECHO} "use of the rsaref package.";	\
		${FALSE};				\
	fi

do-configure:
	@${RM} -f ${WRKDIR}/source/rsaref && ${LN} -sf . ${WRKDIR}/source/rsaref

do-install:
	${MKDIR} ${PREFIX}/include/rsaref ${PREFIX}/share/doc/rsaref
	cd ${WRKSRC} && ${LIBTOOL} ${INSTALL_DATA} librsaref.la ${PREFIX}/lib
.for file in des.h global.h md2.h md5.h rsa.h rsaref.h
	${INSTALL_DATA} ${WRKDIR}/source/${file} ${PREFIX}/include/rsaref/
.endfor
	cd ${WRKDIR}/doc && ${INSTALL_DATA} info.txt rsaref.txt ${PREFIX}/share/doc/rsaref/

.include "../../mk/bsd.pkg.mk"
