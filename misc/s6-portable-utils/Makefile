# $NetBSD: Makefile,v 1.19 2025/05/13 03:49:29 schmonz Exp $

DISTNAME=		s6-portable-utils-2.3.1.0
MANPAGES_VERSION=	2.3.0.3.1
CATEGORIES=		misc
MASTER_SITES=		${HOMEPAGE}
MANPAGES_DIST=		s6-portable-utils-man-pages-${MANPAGES_VERSION}.tar.gz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES_DIST}
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/${PKGBASE}-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.skarnet.org/software/s6-portable-utils/
COMMENT=		Tiny portable generic utilties
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

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
