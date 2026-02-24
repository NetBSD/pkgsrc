# $NetBSD: Makefile,v 1.9 2026/02/24 08:45:34 bsiegert Exp $

DISTNAME=	adguardhome-0.107.72
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdguardTeam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	AdGuardHome

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdguardTeam/AdGuardHome
COMMENT=	Powerful network-wide ads and trackers blocking DNS server
LICENSE=	gnu-gpl-v3

# Because frontend is not versioned, fetch it, rename to
# adguardhome_frontend-${PKGVERSION_NOREV}.tar.gz
# and upload to MASTER_SITE_LOCAL (make upload-distfiles).
#FRONTEND=		AdGuardHome_frontend.tar.gz
#SITES.${FRONTEND}=	${MASTER_SITE_GITHUB:=AdguardTeam/}${GITHUB_PROJECT}/releases/download/${GITHUB_TAG}/
FRONTEND=		adguardhome_frontend-${PKGVERSION_NOREV}.tar.gz
SITES.${FRONTEND}=	${MASTER_SITE_LOCAL}

DISTFILES=	${DEFAULT_DISTFILES} ${FRONTEND}
EXTRACT_ONLY=	${DEFAULT_DISTFILES} ${FRONTEND}

CHECK_RELRO_SKIP+=	bin/AdGuardHome

OWN_DIRS+=	libdata/adguardhome

.include "go-modules.mk"

GOFLAGS=		--ldflags='-s -w \
			-X github.com/AdguardTeam/AdGuardHome/internal/version.version=v${PKGVERSION_NOREV} \
			-X github.com/AdGuardTeam/AdGuardHome/internal/version..channel=release'
GO_BUILD_PATTERN=	.
INSTALLATION_DIRS+=	libdata/adguardhome
PKG_SYSCONFSUBDIR=	adguardhome
RCD_SCRIPTS+=		adguardhome

SUBST_CLASSES+=		rcconf
SUBST_STAGE.rcconf=	pre-configure
SUBST_MESSAGE.rcconf=	Subsituting pkgsrc variables.
SUBST_FILES.rcconf=	internal/ossvc/config_netbsd.go
SUBST_VARS.rcconf=	PKG_SYSCONFDIR PREFIX RCD_SCRIPTS_SHELL VARBASE

# Hack: see https://github.com/AdguardTeam/AdGuardHome/pull/8142
post-patch:
	${LN} ${WRKSRC}/internal/aghnet/net_freebsd.go ${WRKSRC}/internal/aghnet/net_netbsd.go
	${CP} -R ${WRKDIR}/build/static ${WRKSRC}/build/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
