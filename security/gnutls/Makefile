# $NetBSD: Makefile,v 1.52 2006/09/16 06:21:22 wiz Exp $

DISTNAME=	gnutls-1.4.4
CATEGORIES=	security devel
MASTER_SITES=	http://josefsson.org/gnutls/releases/ \
		ftp://ftp.gnutls.org/pub/gnutls/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/ \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-security/gnutls/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		# PLIST

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libextra/gnutls-extra.pc.in

BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.5
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=0.3.4
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.2

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gnutls

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnutls.ps ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
