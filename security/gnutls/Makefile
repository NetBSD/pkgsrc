# $NetBSD: Makefile,v 1.135 2013/11/29 22:55:29 wiz Exp $

DISTNAME=	gnutls-3.2.7
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/gcrypt/gnutls/v3.2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-p11-kit
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=	--disable-openssl-compatibility
CONFIGURE_ARGS+=	--disable-guile
CONFIGURE_ARGS+=	--without-tpm

TEST_TARGET=		check
INFO_FILES=		yes

REPLACE_PERL+=	doc/scripts/gdoc doc/scripts/sort2.pl

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libdane/gnutls-dane.pc.in

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} include/gnutls

post-install:
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${DESTDIR}${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=0.3.4
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
# guile is useful for selftests, but bindings should be separate pkgs
#.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
