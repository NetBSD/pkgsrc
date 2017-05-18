# $NetBSD: Makefile,v 1.171 2017/05/18 07:54:26 he Exp $

DISTNAME=	gnutls-3.5.12
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/gcrypt/gnutls/v3.5/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake gsed perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-p11-kit
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=	--disable-openssl-compatibility
CONFIGURE_ARGS+=	--disable-guile
CONFIGURE_ARGS+=	--disable-libdane
CONFIGURE_ARGS+=	--without-tpm
CONFIGURE_ARGS+=	--disable-valgrind-tests
# Assembler support is broken for SunOS in 3.2.9.
CONFIGURE_ARGS.SunOS+=	--disable-hardware-acceleration
CONFIGURE_ARGS.FreeBSD+=ac_cv_type_max_align_t=yes

# as of 3.5.8, 0 test failures
TEST_TARGET=		check
# without the USE_TOOLS line below, the fastopen.sh test fails
# but when this line is added, the tool path for bash is embedded
# in to the binaries, so only enable this for testing and
# disable before commit
#USE_TOOLS+=		bash

INFO_FILES=		yes

REPLACE_BASH+=		tests/cert-tests/openpgp-certs
REPLACE_BASH+=		tests/danetool.sh
REPLACE_BASH+=		tests/ocsp-tests/ocsp-must-staple-connection
REPLACE_BASH+=		tests/ocsp-tests/ocsp-tls-connection
REPLACE_BASH+=		tests/key-tests/dsa
REPLACE_BASH+=		tests/suite/testcompat-main-polarssl
REPLACE_BASH+=		tests/suite/testcompat-main-openssl
REPLACE_BASH+=		tests/fastopen.sh
REPLACE_BASH+=		tests/starttls.sh

REPLACE_PERL+=	doc/scripts/gdoc doc/scripts/sort2.pl

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libdane/gnutls-dane.pc.in

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

EGDIR=		${PREFIX}/share/examples/gnutls

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} include/gnutls

post-install:
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${DESTDIR}${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/autogen/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libcfg+/buildlink3.mk"
# Avoid creating a fake zlib.pc, because if it does
# gnutls will add a Requires.private for it in its .pc file
CHECK_BUILTIN.zlib:=yes
.include "../../devel/zlib/buildlink3.mk"
# guile is useful for selftests, but bindings should be separate pkgs
#.include "../../lang/guile20/buildlink3.mk"
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=4.9
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
