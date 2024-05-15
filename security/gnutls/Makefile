# $NetBSD: Makefile,v 1.250 2024/05/15 08:13:25 nia Exp $

DISTNAME=	gnutls-3.8.5
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://www.gnupg.org/ftp/gcrypt/gnutls/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnutls.org/
COMMENT=	Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

PLIST_SRC=	PLIST

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
GCC_REQD+=		6

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gsed perl pkg-config bash
USE_TOOLS+=		msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=	--disable-openssl-compatibility
CONFIGURE_ARGS+=	--without-idn
CONFIGURE_ARGS+=	--without-tpm
CONFIGURE_ARGS+=	--disable-valgrind-tests
CONFIGURE_ARGS+=	--with-default-trust-store-file=${PREFIX}/share/mozilla-rootcerts/cacert.pem
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}

# Assembler support is broken for SunOS in 3.2.9.
CONFIGURE_ARGS.SunOS+=		--disable-hardware-acceleration
CONFIGURE_ARGS.FreeBSD+=	ac_cv_type_max_align_t=yes

.include "options.mk"

# one failure as of 3.7.1
# https://gitlab.com/gnutls/gnutls/-/issues/1190
TEST_TARGET=		check

INFO_FILES=		yes

REPLACE_BASH+=		tests/danetool.sh
REPLACE_BASH+=		tests/fastopen.sh
REPLACE_BASH+=		tests/gnutls-cli-debug.sh
REPLACE_BASH+=		tests/starttls.sh

REPLACE_PERL+=		doc/scripts/gdoc doc/scripts/sort2.pl

PKGCONFIG_OVERRIDE=	lib/gnutls.pc.in
PKGCONFIG_OVERRIDE+=	libdane/gnutls-dane.pc.in

MAKE_ENV+=		RM=${RM:Q}
MAKE_ENV+=		TZ=UTC

INSTALLATION_DIRS=	${EGDIR} include/gnutls

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
GNUTLS_GAS_VERSION!=	\
	( env LC_ALL=C as --version 2>&1 | ${GREP} 'GNU assembler version' | ${AWK} '{print $$4}') 2>/dev/null || ${ECHO} 0
.  if ${GNUTLS_GAS_VERSION} != 0
GNUTLS_GAS_NEW_ENOUGH=	no
# for ssse3, >=2.22
# better to TOOL_DEPENDS on binutils's gas
GNUTLS_GAS_ACCEPTABLE_PATTERNS=	\
	2.2[2-9]		\
	2.2[2-9].*		\
	2.2[2-9]-[0-9]*.*	\
	2.[3-9][0-9]		\
	2.[3-9][0-9].*		\
	2.[3-9][0-9]-[0-9]*.*	\
	[3-9]*.*
.    for gas_pattern in ${GNUTLS_GAS_ACCEPTABLE_PATTERNS}
.      if !empty(GNUTLS_GAS_VERSION:M${gas_pattern})
GNUTLS_GAS_NEW_ENOUGH=	yes
.      endif
.    endfor
.    if !empty(GNUTLS_GAS_NEW_ENOUGH:M[nN][oO])
CONFIGURE_ARGS+=	--disable-hardware-acceleration
.    endif
.  endif
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64}
# don't assume GNU as(1) here
BUILDLINK_TRANSFORM+=	rm:-Wa,-march=all
.endif

# Tests fail due to missing strndup for Solaris < 5.11, disable for now
.if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} < 051100
CONFIGURE_ARGS.SunOS+=	--disable-tests
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gmp+=		gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
# Avoid creating a fake zlib.pc, because if it does
# gnutls will add a Requires.private for it in its .pc file
CHECK_BUILTIN.zlib:=yes
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libtasn1+=	libtasn1>=4.9
.include "../../security/libtasn1/buildlink3.mk"
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.6
.include "../../security/nettle/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
