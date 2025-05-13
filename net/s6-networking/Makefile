# $NetBSD: Makefile,v 1.23 2025/05/13 03:50:51 schmonz Exp $

DISTNAME=		s6-networking-2.7.1.0
MANPAGES_VERSION=	2.7.0.4.1
CATEGORIES=		net
MASTER_SITES=		${HOMEPAGE}
MANPAGES_DIST=		s6-networking-man-pages-${MANPAGES_VERSION}.tar.gz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/${PKGBASE}-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/s6-networking/
COMMENT=		Suite of small networking utilities
LICENSE=		isc

TOOL_DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

WRKMANSRC=		${WRKDIR}/${PKGBASE}-man-pages-v${MANPAGES_VERSION}

USE_TOOLS+=		gmake
TOOLS_PLATFORM.install=	${PREFIX}/bin/ginstall
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig

INSTALL_DIRS+=		. ${WRKMANSRC}
INSTALL_ENV+=		PREFIX=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "options.mk"

.include "../../devel/skalibs/buildlink3.mk"
.include "../../net/s6-dns/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
