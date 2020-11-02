# $NetBSD: Makefile,v 1.15 2020/11/02 08:17:43 schmonz Exp $

DISTNAME=	libressl-2.7.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_OPENBSD:=LibreSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libressl.org/
COMMENT=	Secure Sockets Layer and cryptography libraries and tools
LICENSE=	openssl

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libcrypto.pc.in
PKGCONFIG_OVERRIDE+=	libssl.pc.in
PKGCONFIG_OVERRIDE+=	libtls.pc.in
PKGCONFIG_OVERRIDE+=	openssl.pc.in

LIBRESSL_PREFIX=	${PREFIX}/${PKGBASE}

PKG_SYSCONFSUBDIR=	${PKGBASE}
GNU_CONFIGURE_PREFIX=	${LIBRESSL_PREFIX}
CONFIGURE_ARGS+=	--with-openssldir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	${EGDIR} lib

EGDIR=			${PREFIX}/libressl/share/examples/${PKGBASE}
CONFS=			cert.pem openssl.cnf x509v3.cnf
.for f in ${CONFS}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Handle subprefix
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LIBRESSL_PREFIX:Q}/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${LIBRESSL_PREFIX:Q}/lib

TEST_TARGET=	check
PLIST_VARS+=	man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
# bn_print(3) and BN_print(3) conflict on case-insensitive file system
PLIST.man=	yes
.endif

post-install:
	cd ${WRKSRC}/apps/openssl; ${INSTALL_DATA} ${CONFS} ${DESTDIR}${EGDIR}
	mv ${DESTDIR}${PREFIX}/libressl/lib/pkgconfig ${DESTDIR}${PREFIX}/lib
	${RM} -r ${DESTDIR}${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
