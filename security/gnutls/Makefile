# $NetBSD: Makefile,v 1.21 2004/10/06 10:17:06 grant Exp $

DISTNAME=	gnutls-1.0.20
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/ \
		http://www.mirrors.wiretapped.net/security/network-security/gnutls/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-security/gnutls/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

BUILDLINK_DEPENDS.opencdk=	opencdk>=0.5.5

MAKE_ENV+=		RM="${RM}"

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/gnutls

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCDIR}
	cd ${WRKSRC}/doc/tex && ${INSTALL_DATA} *.ps *.tex *.eps ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${EGDIR}

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
