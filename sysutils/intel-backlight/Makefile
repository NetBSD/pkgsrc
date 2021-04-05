# $NetBSD: Makefile,v 1.4 2021/04/05 10:20:47 tnn Exp $

DISTNAME=	intel_backlight_fbsd-20200418
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/^intel_backlight_fbsd/intel-backlight/1}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeBSDDesktop/}
GITHUB_PROJECT=	intel_backlight_fbsd
GITHUB_TAG=	a6c0e390a3d069870828713a8ba3475b31f87804

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FreeBSDDesktop/intel_backlight_fbsd
COMMENT=	Tool for controlling backlight level on certain Intel GPUs
LICENSE=	mit

BUILD_TARGET=	intel_backlight

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	INCS=
MAKE_FLAGS+=	LIBS=${LDFLAGS:Q}

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64
NOT_FOR_PLATFORM+=	Darwin-*-*

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if empty(UNPRIVILEGED:M[yY][eE][sS])
SPECIAL_PERMS+=	sbin/intel_backlight ${SETUID_ROOT_PERMS}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/intel_backlight \
	    ${DESTDIR}${PREFIX}/sbin/intel_backlight
	${INSTALL_MAN} ${WRKSRC}/intel_backlight.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/intel_backlight.1

.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
