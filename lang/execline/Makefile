# $NetBSD: Makefile,v 1.28 2025/07/08 21:45:34 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		execline-2.9.7.0
PKGREVISION=		1
MANPAGES_VERSION=	2.9.6.1.1
CATEGORIES=		lang shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		execline
GITHUB_TAG=		d7eb7a92cd7511f3a3f8bcd6f9652bd53de75cc5
DISTFILES=		${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX} ${MANPAGES_DIST}
MANPAGES_DIST=		execline-man-pages-${MANPAGES_VERSION}.tar.gz
SITES.${MANPAGES_DIST}=	-https://git.sr.ht/~flexibeast/${PKGBASE}-man-pages/archive/v${MANPAGES_VERSION}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/execline/
COMMENT=		The execline scripting language
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
