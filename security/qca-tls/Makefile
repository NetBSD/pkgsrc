# $NetBSD: Makefile,v 1.9 2005/09/28 14:31:08 rillig Exp $

DISTNAME=	qca-tls-1.0
PKGREVISION=	# empty
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORCE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT - TLS plugin

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=        --with-openssl-inc=${SSLBASE}/include
CONFIGURE_ARGS+=        --with-openssl-lib=${SSLBASE}/lib

# XXX the -rpath filter is somewhat ugly, and this should be eventually
# fixed in NetBSD qmake template to not be necessary.
post-configure:
	cd ${WRKSRC} && ( ${SETENV} ${CONFIGURE_ENV}			\
		${QTDIR}/bin/qmake qca-tls.pro -o Makefile.orig;	\
		${SED} -e "s,-rpath .*,-rpath ${QTDIR}/lib," Makefile.orig > Makefile;	\
	)

do-install:
	${INSTALL_DATA_DIR} ${QTDIR}/plugins/crypto
	cd ${WRKSRC} && \
	libtool --mode=install ${INSTALL_LIB} libqca-tls.la ${QTDIR}/plugins/crypto

.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
