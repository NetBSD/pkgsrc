# $NetBSD: Makefile,v 1.5 2024/07/19 09:51:36 jperkin Exp $

DISTNAME=	wireguard-tools-1.0.20210914
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://git.zx2c4.com/wireguard-tools/snapshot/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://git.zx2c4.com/wireguard-tools/about/
COMMENT=	Userspace tooling for using and configuring WireGuard tunnels
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_FLAGS+=	WITH_BASHCOMPLETION=yes
MAKE_FLAGS+=	WITH_SYSTEMDUNITS=no

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	completion/wg-quick.bash-completion
SUBST_FILES.paths+=	wg-quick/*.bash
SUBST_SED.paths=	-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

PLIST_VARS+=		wg-quick
PRINT_PLIST_AWK+=	/wg-quick/ { print "$${PLIST.wg-quick}" $$0; next }

.include "../../mk/bsd.prefs.mk"

# Darwin's native bash 3.x isn't sufficient
.if ${OPSYS} == "Darwin" && "${TOOLS_PLATFORM.bash}" == "/bin/bash"
TOOLS_PLATFORM.bash=
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD" \
 || ${OPSYS} == "Linux" || ${OPSYS} == "OpenBSD"
USE_TOOLS+=		bash:run
REPLACE_BASH+=		wg-quick/*.bash
MAKE_FLAGS+=		WITH_WGQUICK=yes
PLIST.wg-quick=		yes
.else
MAKE_FLAGS+=		WITH_WGQUICK=no
.endif

.include "../../mk/bsd.pkg.mk"
