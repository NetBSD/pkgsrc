# $NetBSD: Makefile,v 1.59 2007/04/20 06:07:15 wiz Exp $

DISTNAME=	gnutls-1.6.2
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
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		yes

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libextra/gnutls-extra.pc.in

BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.5
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=0.3.4
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.2

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} include/gnutls

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnutls.ps ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${DESTDIR}${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
