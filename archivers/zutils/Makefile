# $NetBSD: Makefile,v 1.17 2026/08/26 07:31:44 drixter Exp $

DISTNAME=       zutils-1.16
CATEGORIES=     archivers
MASTER_SITES=   http://download-mirror.savannah.gnu.org/releases/zutils/
EXTRACT_SUFX=   .tar.lz

MAINTAINER=     drixter@e-utp.net
HOMEPAGE=       https://www.nongnu.org/zutils/zutils.html
COMMENT=        Utilities for any combination of compressed and non-compressed files
LICENSE=        gnu-gpl-v3

CONFLICTS=              lzip<1.12 gzip-[0-9]*

HAS_CONFIGURE=          yes
CONFIGURE_ARGS+=        --prefix=${PREFIX}
CONFIGURE_ARGS+=        --mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=        --infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=        LDFLAGS=${LDFLAGS:Q}
CONFIGURE_ARGS+=        CPPFLAGS=${CPPFLAGS:Q}
CONFIGURE_ARGS+=        CXXFLAGS=${CXXFLAGS:Q}

USE_LANGUAGES=          c++
USE_TOOLS+=             gmake

INFO_FILES=             yes

EGDIR=                  ${PREFIX}/share/examples/zutils
CONF_FILES+=            ${EGDIR}/zutils.conf ${PKG_SYSCONFDIR}/zutils.conf

INSTALLATION_DIRS=      ${EGDIR}

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/zutils.conf ${DESTDIR}${EGDIR}/zutils.conf

.include "../../mk/bsd.pkg.mk"


