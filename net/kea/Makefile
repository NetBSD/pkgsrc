# $NetBSD: Makefile,v 1.2 2023/01/22 16:28:35 ryoon Exp $

DISTNAME=	kea-${VERSION}
#PKGREVISION=	1
COMMENT=	Next-generation ISC Dynamic Host Configuration Protocol (DHCP) Server
PKGREVISION=	1

.include "options.mk"

CATEGORIES=		net
MASTER_SITES=		https://ftp.isc.org/isc/kea/${VERSION}/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		https://www.isc.org/kea/
LICENSE=		mpl-2.0

VERSION=		2.2.0

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKG_SYSCONFSUBDIR=	kea

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c99 c++

RCD_SCRIPTS=		kea

post-install:
	cd ${DESTDIR} && \
	mkdir -p ${DESTDIR}${PREFIX}/share/examples/kea && \
	mv ${DESTDIR}${PKG_SYSCONFDIR}/*.conf \
		${DESTDIR}${PREFIX}/share/examples/kea/

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

MAKE_DIRS+=		${VARBASE}/lib/kea
MAKE_DIRS+=		${VARBASE}/run/kea

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"

.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
