# $NetBSD: Makefile,v 1.24.2.2 2002/08/22 11:12:34 jlam Exp $
#

DISTNAME=		rsaref
PKGNAME=		rsaref-2.0p3
WRKSRC=			${WRKDIR}/install
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.spinnaker.com/pub/crypt/rsaref/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
COMMENT=		Encryption/authentication library, RSA/MDX/DES

CRYPTO=			yes
LICENSE=		no-commercial-use

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
MAKEFILE=		unix/makefile
ALL_TARGET=		librsaref.la

do-configure:
	@${RM} -f ${WRKDIR}/source/rsaref && ${LN} -sf . ${WRKDIR}/source/rsaref

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/rsaref ${PREFIX}/share/doc/rsaref
	cd ${WRKSRC} && ${LIBTOOL} ${INSTALL_DATA} librsaref.la ${PREFIX}/lib
.for file in des.h global.h md2.h md5.h rsa.h rsaref.h
	${INSTALL_DATA} ${WRKDIR}/source/${file} ${PREFIX}/include/rsaref/
.endfor
	cd ${WRKDIR}/doc && ${INSTALL_DATA} info.txt rsaref.txt ${PREFIX}/share/doc/rsaref/

.include "../../mk/bsd.pkg.mk"
