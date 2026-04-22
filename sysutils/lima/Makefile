# $NetBSD: Makefile,v 1.9.2.1 2026/04/22 14:32:16 maya Exp $

DISTNAME=	lima-1.2.1
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lima-vm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/lima-vm/lima
COMMENT=	Linux virtual machines for running containerd
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

DEPENDS+=	qemu-[0-9]*:../../emulators/qemu

# Avoid to invoke/use git
MAKE_FLAGS+=	VERSION=${GITHUB_TAG}

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

do-build:
	cd ${WRKSRC} && \
	${RUN} ${_ULIMIT_CMD} \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			${BUILD_TARGET}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc

do-install:
	${RUN} cd ${WRKSRC}/_output && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	${RUN} cd ${WRKSRC}/_output/share/man && ${PAX} -rw man1 ${DESTDIR}${PREFIX}/${PKGMANDIR}
	${RUN} cd ${WRKSRC}/_output/share/doc && ${PAX} -rw lima ${DESTDIR}${PREFIX}/share/doc
	${RUN} cd ${WRKSRC}/_output/share && ${PAX} -rw lima ${DESTDIR}${PREFIX}/share

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
