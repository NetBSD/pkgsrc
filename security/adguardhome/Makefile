# $NetBSD: Makefile,v 1.11 2026/03/06 21:08:00 bsiegert Exp $

AGH_VERSION=	0.107.72
DISTNAME=	adguardhome-${AGH_VERSION}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdguardTeam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	AdGuardHome

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdguardTeam/AdGuardHome
COMMENT=	Powerful network-wide ads and trackers blocking DNS server
LICENSE=	gnu-gpl-v3

FRONTEND=		adguardhome_frontend-${AGH_VERSION}.tar.gz
SITES.${FRONTEND}=	-${MASTER_SITE_GITHUB:=AdguardTeam/}${GITHUB_PROJECT}/releases/download/${GITHUB_TAG}/AdGuardHome_frontend.tar.gz

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
