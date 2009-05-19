# $NetBSD: Makefile,v 1.38 2009/05/19 08:59:33 wiz Exp $
#

DISTNAME=		rsaref
PKGNAME=		rsaref-2.0p3
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.spinnaker.com/crypt/rsaref/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Encryption/authentication library, RSA/MDX/DES
LICENSE=		rsaref-license

RESTRICTED=		No generation of income.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/install
CRYPTO=			yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
MAKE_FILE=		unix/makefile
BUILD_TARGET=		librsaref.la

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
