# $NetBSD: Makefile,v 1.22 2007/12/20 20:37:24 jdolecek Exp $

DISTNAME=	qca-tls-1.0
PKGREVISION=	# empty
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORCE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes

post-configure:
	cd ${WRKSRC} && (	\
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
