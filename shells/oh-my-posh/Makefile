# $NetBSD: Makefile,v 1.4 2023/04/07 00:32:56 schmonz Exp $

DISTNAME=		oh-my-posh-14.14.3
PKGREVISION=		1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=JanDeDobbeleer/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://ohmyposh.dev/
COMMENT=		Prompt theme engine for any shell
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_LANGUAGES=		c

SUBST_CLASSES+=		version
SUBST_STAGE.version=	do-configure
SUBST_FILES.version=	main.go
SUBST_SED.version=	-e 's|"development"|"${PKGVERSION_NOREV}"|'

INSTALLATION_DIRS=	share/${PKGBASE}

# XXX is this still fine on Darwin? Linux?
post-extract:
	# won't report useful battery status on non-Linux, but at least it'll compile
	${MV} ${WRKSRC}/platform/battery/battery_linux.go ${WRKSRC}/platform/battery/battery_unix.go
	# NetBSD and Illumos are just weird kinds of Linux, doncha know
	${MV} ${WRKDIR}/github.com/gookit/goutil@v0.6.7/sysutil/sysutil_linux.go \
		${WRKDIR}/github.com/gookit/goutil@v0.6.7/sysutil/sysutil_unix.go

post-build:
	${MV} ${WRKDIR}/.gopath/bin/src ${WRKDIR}/.gopath/bin/oh-my-posh

post-install:
	cd ${WRKDIR}/${DISTNAME}/themes &&				\
	for f in *.json *.yaml; do					\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/${PKGBASE};	\
	done

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
