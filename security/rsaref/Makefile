# $NetBSD: Makefile,v 1.31 2004/10/03 00:18:13 tv Exp $
#

DISTNAME=		rsaref
PKGNAME=		rsaref-2.0p3
PKGREVISION=	1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.spinnaker.com/pub/crypt/rsaref/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Encryption/authentication library, RSA/MDX/DES

WRKSRC=			${WRKDIR}/install
CRYPTO=			yes
LICENSE=		no-commercial-use

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
MAKEFILE=		unix/makefile
ALL_TARGET=		librsaref.la

do-configure:
	@${RM} -f ${WRKDIR}/source/rsaref && ${LN} -sf . ${WRKDIR}/source/rsaref

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/rsaref
	cd ${WRKSRC} && ${LIBTOOL} ${INSTALL_DATA} librsaref.la ${PREFIX}/lib
.for file in des.h global.h md2.h md5.h rsa.h rsaref.h
	${INSTALL_DATA} ${WRKDIR}/source/${file} ${PREFIX}/include/rsaref/
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rsaref
	cd ${WRKDIR}/doc && ${INSTALL_DATA} info.txt rsaref.txt ${PREFIX}/share/doc/rsaref/

.include "../../mk/bsd.pkg.mk"
