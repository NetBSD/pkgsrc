# $NetBSD: Makefile,v 1.13 2025/02/06 00:00:44 riastradh Exp $

DISTNAME=	kea-${VERSION}
COMMENT=	Next-generation ISC Dynamic Host Configuration Protocol (DHCP) Server
PKGREVISION=	2

.include "options.mk"

CATEGORIES=		net
MASTER_SITES=		https://ftp.isc.org/isc/kea/${VERSION}/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		https://www.isc.org/kea/
LICENSE=		mpl-2.0

VERSION=		2.6.1

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKG_SYSCONFSUBDIR=	kea

USE_TOOLS+=		autoconf gmake
USE_LANGUAGES+=		c++ c
USE_CC_FEATURES+=	c99

RCD_SCRIPTS=		kea

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

post-install:
	cd ${DESTDIR} && \
	mkdir -p ${DESTDIR}${PREFIX}/share/examples/kea && \
	mv ${DESTDIR}${PKG_SYSCONFDIR}/*.conf \
		${DESTDIR}${PREFIX}/share/examples/kea/

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

MAKE_DIRS+=		${VARBASE}/lib/kea
MAKE_DIRS+=		${VARBASE}/run/kea

.if ${USE_CROSS_COMPILE:tl} == "yes"
# This appears to store an absolute path to the bison(1) executable
# which lives in TOOLBASE (or possibly in TOOLS_DIR).
CHECK_WRKREF_SKIP+=	lib/libkea-process*
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
