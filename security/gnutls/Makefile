# $NetBSD: Makefile,v 1.209 2020/03/22 12:21:59 rillig Exp $

DISTNAME=	gnutls-3.6.12
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://www.gnupg.org/ftp/gcrypt/gnutls/v3.6/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnutls.org/
COMMENT=	Transport Layer Security library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

PLIST_SRC=	PLIST

USE_LANGUAGES=			c c++
USE_LIBTOOL=			yes
USE_TOOLS+=			gmake gsed perl pkg-config bash
USE_TOOLS+=			msgfmt msgmerge xgettext
GNU_CONFIGURE=			yes
# this library duplicates (and conflicts with) openssl
CONFIGURE_ARGS+=		--disable-openssl-compatibility
CONFIGURE_ARGS+=		--disable-guile
CONFIGURE_ARGS+=		--disable-libdane
CONFIGURE_ARGS+=		--without-idn
CONFIGURE_ARGS+=		--without-tpm
CONFIGURE_ARGS+=		--disable-valgrind-tests
CONFIGURE_ARGS+=		--with-default-trust-store-file=${PREFIX}/share/mozilla-rootcerts/cacert.pem
CONFIGURE_ARGS+=		--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
CONFIGURE_ARGS+=		--enable-local-libopts
# Assembler support is broken for SunOS in 3.2.9.
CONFIGURE_ARGS.SunOS+=		--disable-hardware-acceleration
CONFIGURE_ARGS.FreeBSD+=	ac_cv_type_max_align_t=yes

.include "options.mk"

TEST_TARGET=		check

INFO_FILES=		yes

REPLACE_BASH+=		tests/cert-tests/certtool
REPLACE_BASH+=		tests/danetool.sh
REPLACE_BASH+=		tests/fastopen.sh
REPLACE_BASH+=		tests/gnutls-cli-debug.sh
REPLACE_BASH+=		tests/ocsp-tests/ocsp-must-staple-connection
REPLACE_BASH+=		tests/ocsp-tests/ocsp-tls-connection
REPLACE_BASH+=		tests/starttls.sh
REPLACE_BASH+=		tests/cert-tests/pkcs12-utf8

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
BUILDLINK_API_DEPENDS.nettle+=		nettle>=3.4.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23.1
.include "../../security/p11-kit/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
