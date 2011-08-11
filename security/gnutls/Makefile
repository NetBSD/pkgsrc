# $NetBSD: Makefile,v 1.102 2011/08/11 11:03:35 adam Exp $

DISTNAME=	gnutls-2.12.8
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/ \
		ftp://ftp.gnupg.org/gcrypt/gnutls/ \
		${MASTER_SITE_GNU:=gnutls/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-p11-kit
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=	--disable-openssl-compatibility

TEST_TARGET=		check
INFO_FILES=		yes

REPLACE_PERL+=	doc/scripts/gdoc doc/scripts/sort2.pl

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libextra/gnutls-extra.pc.in

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
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=0.3.4
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
# guile is useful for selftests, but bindings should be separate pkgs
#.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
