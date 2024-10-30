# $NetBSD: Makefile,v 1.19 2024/10/30 12:50:23 adam Exp $

DISTNAME=	libressl-4.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_OPENBSD:=LibreSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libressl.org/
COMMENT=	Secure Sockets Layer and cryptography libraries and tools
LICENSE=	openssl

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

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

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${DESTDIR}${PKG_SYSCONFDIR} && ${INSTALL_DATA} ${CONFS} ${DESTDIR}${EGDIR}
	${RM} -r ${DESTDIR}${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
