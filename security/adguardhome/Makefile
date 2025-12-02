# $NetBSD: Makefile,v 1.2 2025/12/02 19:25:17 bsiegert Exp $

DISTNAME=	adguardhome-0.107.69
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdguardTeam/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	AdGuardHome

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdguardTeam/AdGuardHome
COMMENT=	Powerful network-wide ads and trackers blocking DNS server
LICENSE=	gnu-gpl-v3

STATIC_DIST=		${PKGNAME_NOREV}-static${EXTRACT_SUFX}
SITES.${STATIC_DIST}=	${MASTER_SITE_LOCAL}

# comment out these for: make generate-static
DISTFILES=	${DEFAULT_DISTFILES} ${STATIC_DIST}
EXTRACT_ONLY=	${DEFAULT_DISTFILES} ${STATIC_DIST}

CHECK_RELRO_SKIP+=	bin/AdGuardHome

OWN_DIRS+=	libdata/adguardhome

.include "go-modules.mk"

GO_BUILD_PATTERN=	--ldflags='-s -w \
			-X github.com/AdguardTeam/AdGuardHome/internal/version.version=v${PKGVERSION_NOREV} \
			-X github.com/AdGuardTeam/AdGuardHome/internal/version..channel=release'
INSTALLATION_DIRS+=	libdata/adguardhome
PKG_SYSCONFSUBDIR=	adguardhome
RCD_SCRIPTS+=		adguardhome

# Hack
post-patch:
	${LN} ${WRKSRC}/internal/aghnet/net_freebsd.go ${WRKSRC}/internal/aghnet/net_netbsd.go

# Install lang/nodejs and run this target.
.PHONY: generate-static
generate-static:
	cd ${WRKSRC}/client && npm install && npm run build-prod
	cd ${WRKDIR} && ${TAR} -zcf ${DISTDIR}/${PKGNAME_NOREV}-static.tar.gz AdGuardHome-${PKGVERSION_NOREV}/build/static
	@${ECHO} "Run: make upload-distfiles"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
