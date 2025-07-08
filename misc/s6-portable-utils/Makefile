# $NetBSD: Makefile,v 1.21 2025/07/08 21:45:34 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		s6-portable-utils-2.3.1.0
PKGREVISION=		1
MANPAGES_VERSION=	2.3.0.4.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		s6-portable-utils
GITHUB_TAG=		e2e283b00702579dee22b5ac769c4933d8cc1865
DISTFILES=		${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX} ${MANPAGES_DIST}
MANPAGES_DIST=		s6-portable-utils-man-pages-${MANPAGES_VERSION}.tar.gz
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
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

INSTALL_DIRS+=		. ${WRKMANSRC}
INSTALL_ENV+=		PREFIX=${PREFIX:Q} MAN_DIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
