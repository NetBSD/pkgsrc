# $NetBSD: Makefile,v 1.188 2018/08/22 09:46:18 wiz Exp $

DISTNAME=	gnutls-3.6.3
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/gcrypt/gnutls/v3.6/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

USE_LANGUAGES=			c c++
USE_LIBTOOL=			yes
USE_PKGLOCALEDIR=		yes
USE_TOOLS+=			gmake gsed perl pkg-config bash
GNU_CONFIGURE=			yes
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=		--disable-openssl-compatibility
CONFIGURE_ARGS+=		--disable-guile
CONFIGURE_ARGS+=		--disable-libdane
CONFIGURE_ARGS+=		--without-tpm
CONFIGURE_ARGS+=		--disable-valgrind-tests
CONFIGURE_ARGS+=		--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
CONFIGURE_ARGS+=		--enable-local-libopts
# Assembler support is broken for SunOS in 3.2.9.
CONFIGURE_ARGS.SunOS+=		--disable-hardware-acceleration
CONFIGURE_ARGS.FreeBSD+=	ac_cv_type_max_align_t=yes

# as of 3.5.8, 0 test failures
TEST_TARGET=		check
# without the USE_TOOLS line below, the fastopen.sh test fails
# but when this line is added, the tool path for bash is embedded
# in to the binaries, so only enable this for testing and
# disable before commit
#USE_TOOLS+=		bash

INFO_FILES=		yes

REPLACE_BASH+=		tests/cert-tests/certtool
REPLACE_BASH+=		tests/danetool.sh
REPLACE_BASH+=		tests/fastopen.sh
REPLACE_BASH+=		tests/gnutls-cli-debug.sh
REPLACE_BASH+=		tests/ocsp-tests/ocsp-must-staple-connection
REPLACE_BASH+=		tests/ocsp-tests/ocsp-tls-connection
REPLACE_BASH+=		tests/starttls.sh
REPLACE_BASH+=		tests/suite/cbc-record-check.sh
REPLACE_BASH+=		tests/suite/testcompat-main-openssl
REPLACE_BASH+=		tests/suite/testcompat-main-polarssl

REPLACE_PERL+=		doc/scripts/gdoc doc/scripts/sort2.pl

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libdane/gnutls-dane.pc.in

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

SUBST_CLASSES+=		shell
SUBST_SED.shell+=	-e 's,define POSIX_SHELL .*,define POSIX_SHELL "'${TOOLS_PATH.bash}'",'
SUBST_STAGE.shell=	post-configure
SUBST_FILES.shell+=	config.h
SUBST_MESSAGE.shell=	Fixing path to bash.

EGDIR=		${PREFIX}/share/examples/gnutls

INSTALLATION_DIRS=	${EGDIR} include/gnutls

post-install:
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${DESTDIR}${EGDIR}

.include "../../archivers/lzo/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmp+=		gmp>=5.0
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
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23.1
.include "../../security/p11-kit/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
