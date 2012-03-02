# $NetBSD: Makefile,v 1.40 2012/03/02 16:42:06 hans Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES+=		cdefs
USE_LIBTOOL=		yes
MAKE_FILE=		unix/makefile
BUILD_TARGET=		librsaref.la

INSTALLATION_DIRS=	lib include/rsaref share/doc/rsaref

do-configure:
	@${RM} -f ${WRKDIR}/source/rsaref && ${LN} -sf . ${WRKDIR}/source/rsaref

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
	    librsaref.la ${DESTDIR}${PREFIX}/lib
.for file in des.h global.h md2.h md5.h rsa.h rsaref.h
	${INSTALL_DATA} ${WRKDIR}/source/${file} ${DESTDIR}${PREFIX}/include/rsaref/
.endfor
	cd ${WRKDIR}/doc && ${INSTALL_DATA} info.txt rsaref.txt \
	    ${DESTDIR}${PREFIX}/share/doc/rsaref/

.include "../../mk/bsd.pkg.mk"
