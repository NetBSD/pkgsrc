# $NetBSD: Makefile,v 1.3 2026/10/20 20:28:10 bsiegert Exp $

DISTNAME=	rcvd-0.3.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rcvd-dns/}
GITHUB_PROJECT=	rcvd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://rcvd.net/
COMMENT=	Privacy-first encrypted DNS engine (DoQ/DoT/DoH, no cleartext)
LICENSE=	mit

GO_VERSION_REQD=	127

.include "go-modules.mk"
.include "../../mk/bsd.prefs.mk"

RCVD_USER?=		rcvd
RCVD_GROUP?=		rcvd

PKG_GROUPS+=		${RCVD_GROUP}
PKG_USERS+=		${RCVD_USER}:${RCVD_GROUP}
PKG_GECOS.${RCVD_USER}=	rcvd DNS daemon
PKG_HOME.${RCVD_USER}=	/nonexistent
PKG_SHELL.${RCVD_USER}=	${NOLOGIN}
PKG_GROUPS_VARS+=	RCVD_GROUP
PKG_USERS_VARS+=	RCVD_USER

RCD_SCRIPTS=		rcvd

BUILD_DEFS+=		VARBASE RCVD_USER RCVD_GROUP

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/rcvd ${RCVD_USER} ${RCVD_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/log/rcvd ${RCVD_USER} ${RCVD_GROUP} 0755

# The example forwarder profile becomes the default config on first install.
EGDIR=			${PREFIX}/share/examples/rcvd
CONF_FILES=		${EGDIR}/rcvd.toml ${PKG_SYSCONFDIR}/rcvd/rcvd.toml

# Stamp version, date, and source into the binary (parity with the release
# recipe). buildDate is derived from SOURCE_DATE_EPOCH so the build stays
# reproducible: pkgsrc sets it (to a fixed value) under PKGSRC_MKREPRO=yes;
# otherwise it is unset and buildDate keeps the source default ("unknown"),
# never a varying wall-clock time. The release tarball carries no .git, so
# the commit is "unknown" too, by design.
GO_LDFLAGS=		-s -w \
			-X main.version=${PKGVERSION_NOREV} \
			-X main.buildSource=pkgsrc
.if !empty(SOURCE_DATE_EPOCH)
BUILD_DATE_cmd=		date -u -d "@${SOURCE_DATE_EPOCH}" +%Y-%m-%dT%H:%M:%SZ 2>/dev/null || \
			date -u -r "${SOURCE_DATE_EPOCH}" +%Y-%m-%dT%H:%M:%SZ
GO_LDFLAGS+=		-X main.buildDate=${BUILD_DATE_cmd:sh}
.endif
GOFLAGS+=		-ldflags=${GO_LDFLAGS:Q}
GO_BUILD_PATTERN=	./cmd/rcvd

# rcvd is a pure-Go static binary (no cgo), matching the upstream release recipe.
MAKE_ENV+=		CGO_ENABLED=0

INSTALLATION_DIRS+=	${EGDIR} share/doc/rcvd/examples ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/mode1-forwarder-3providers.toml \
		${DESTDIR}${EGDIR}/rcvd.toml
.for f in flagship-dualmode mode1-forwarder-3providers mode2-doh-service
	${INSTALL_DATA} ${WRKSRC}/etc/${f}.toml \
		${DESTDIR}${PREFIX}/share/doc/rcvd/examples/${f}.toml
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/rcvd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcvd.1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
