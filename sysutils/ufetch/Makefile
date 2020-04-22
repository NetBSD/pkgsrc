# $NetBSD: Makefile,v 1.4 2020/04/22 08:35:27 pin Exp $

DISTNAME=	ufetch-v0.2
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/jschx/ufetch/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/jschx/ufetch/
COMMENT=	Tiny system info for Unix-like Operating Systems
LICENSE=	isc

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
FLAVOR=	netbsd
.elif ${OPSYS} == "OpenBSD"
FLAVOR=	openbsd
.elif ${OPSYS} == "FreeBSD"
FLAVOR=	freebsd
.elif ${OPSYS} == "Darwin"
FLAVOR=	macos
.elif ${OPSYS} == "Linux"
FLAVOR=	linux
.else
BROKEN=	"Unsupported OS"
.endif

do-install:
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} \
			ufetch-${FLAVOR} ${DESTDIR}${PREFIX}/bin/ufetch
.if ${OPSYS} == "Linux"
.  for f in alpine antergos arch archbang arco artix aux centos crux debian \
          elementary fedora gentoo gnewsense guixsd hyperbola linuxlite mageia \
          manjaro mint mx nixos parabola popos pureos raspbian slackware suse \
          ubuntu void
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} \
			ufetch-${f} ${DESTDIR}${PREFIX}/bin/ufetch-${f}
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
