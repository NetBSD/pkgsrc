# $NetBSD: Makefile,v 1.6 2000/07/12 20:09:33 jlam Exp $
#

DISTNAME=		cups-1.1-source
PKGNAME=		${DISTNAME:S/-source//}
VERS=			${PKGNAME:S/cups-//}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		print
MASTER_SITES=		ftp://ftp2.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.northamerica.net/pub/ESP/cups/${VERS}/ \
			ftp://ftp.funet.fi/mirrors/ftp.easysw.com/pub/cups/${VERS}/ \
			ftp://ftp.fisek.com.tr/pub/cups/${VERS}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.cups.org/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-libtool-unsupported="${LIBTOOL}"
CONFIGURE_ARGS+=	--disable-pam
CONFIGURE_ARGS+=	--enable-rootconfig

CFLAGS+=		-I${LOCALBASE}/include

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cups
	cd ${WRKSRC}/conf; ${INSTALL_DATA} *.conf mime.* \
		${PREFIX}/share/examples/cups
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
