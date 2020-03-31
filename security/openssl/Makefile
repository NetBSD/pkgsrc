# $NetBSD: Makefile,v 1.256 2020/03/31 15:02:31 sevan Exp $

DISTNAME=	openssl-1.1.1f
CATEGORIES=	security
MASTER_SITES=	https://www.openssl.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openssl.org/
COMMENT=	Secure Socket Layer and cryptographic library
LICENSE=	openssl

USE_GCC_RUNTIME=	yes

USE_TOOLS+=		fgrep gmake makedepend perl
BUILD_TARGET=		depend all
TEST_TARGET=		tests

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./config
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--openssldir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	shared

.include "options.mk"

CONFIGURE_ARGS+=	${CFLAGS} ${LDFLAGS}
CONFIGURE_ENV+=		PERL=${PERL5:Q}

# If the config script cannot guess the host system correctly then we need to
# specify it manually and call the Configure script directly.
OPENSSL_HOST.SunOS-i386=	solaris-x86-gcc
OPENSSL_HOST.SunOS-x86_64=	solaris64-x86_64-gcc

.if defined(OPENSSL_HOST.${OPSYS}-${MACHINE_ARCH})
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	${OPENSSL_HOST.${OPSYS}-${MACHINE_ARCH}}
.endif

PKGCONFIG_OVERRIDE+=		libcrypto.pc libssl.pc openssl.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

PKG_SYSCONFSUBDIR=	openssl
CONF_FILES=		${PREFIX}/share/examples/openssl/openssl.cnf	\
			${PKG_SYSCONFDIR}/openssl.cnf
OWN_DIRS=		${PKG_SYSCONFDIR}/certs ${PKG_SYSCONFDIR}/private

INSTALLATION_DIRS+=	share/examples/openssl

#
# Note that this package cannot be updated solely from Darwin, it relies on
# shlib-dylib.awk to convert the normal .so entries to dylib, which doesn't
# work the other way around.  The lib/engines-1.1 plugins also need special
# handling.
#
OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}

PRINT_PLIST_AWK+=	/^lib\/engines/ { gsub(/\.${SOEXT}$$/, ".$${SOEXT}"); }

# Remove CC from the environment, to fix GCC version handling on HP-UX,
# SunOS and Linux/sparc.
#
# See https://github.com/openssl/openssl/issues/11060.
do-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV:NCC=*}	\
		${CONFIG_SHELL} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

#
# Get rid of ridiculous namespace collisions like passwd.1 and just leave the
# openssl-*.1 style variants.  On a more practical note this avoids creating
# a conflict with moreutils (ts.1).
#
post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;			\
	for f in openssl-*; do						\
		${RM} -f $${f};						\
		${MV} `${ECHO} $${f} | ${SED} -e 's/openssl-//'` $${f};	\
	done

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
