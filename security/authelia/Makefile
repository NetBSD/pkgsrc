# $NetBSD: Makefile,v 1.2 2020/11/06 18:15:37 tnn Exp $

DISTNAME=	authelia-4.22.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=authelia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

DISTFILES=			${DEFAULT_DISTFILES}
FE_DISTNAME=			${DISTNAME}.public_html.tar.gz
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		\
	-${MASTER_SITE_GITHUB:=authelia/}/authelia/releases/download/${GITHUB_TAG}/authelia-public_html.tar.gz
EXTRACT_DIR.${FE_DISTNAME}=	${WRKSRC}
BR_DISTNAME=			broccoli-1.0.3.tar.gz
DISTFILES+=			${BR_DISTNAME}
SITES.${BR_DISTNAME}=		\
	-${MASTER_SITE_GITHUB:=aletheia-icu/}broccoli/archive/v1.0.3.tar.gz
EXTRACT_DIR.${BR_DISTNAME}=	${WRKDIR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.authelia.com/
COMMENT=	Single Sign-On Multi-Factor portal for web apps
LICENSE=	apache-2.0

.include "go-modules.mk"

# additional go modules needed to build broccoli
GO_MODULE_FILES+=	aletheia.icu/broccoli/fs/@v/v0.0.0-20200420162907-e7ff440cf358.mod
GO_MODULE_FILES+=	aletheia.icu/broccoli/fs/@v/v0.0.0-20200420162907-e7ff440cf358.zip
GO_MODULE_FILES+=	github.com/sabhiram/go-gitignore/@v/v0.0.0-20180611051255-d3107576ba94.mod
GO_MODULE_FILES+=	github.com/sabhiram/go-gitignore/@v/v0.0.0-20180611051255-d3107576ba94.zip

GO_BUILD_PATTERN=	./cmd/authelia/...

AUTHELIA_USER?=		authelia
AUTHELIA_GROUP?=	authelia
BUILD_DEFS+=		AUTHELIA_USER AUTHELIA_GROUP
FILES_SUBST+=		AUTHELIA_USER=${AUTHELIA_USER:Q}
FILES_SUBST+=		AUTHELIA_GROUP=${AUTHELIA_GROUP:Q}
PKG_USERS=		${AUTHELIA_USER:Q}:${AUTHELIA_GROUP:Q}
PKG_USERS_VARS+=	AUTHELIA_USER
PKG_GROUPS=		${AUTHELIA_GROUP:Q}
PKG_GROUPS_VARS+=	AUTHELIA_GROUP

CONF_FILES_PERMS+=	${PREFIX}/share/examples/authelia/authelia.yml \
			  ${PKG_SYSCONFDIR}/authelia.yml \
			  ${AUTHELIA_USER:Q} ${AUTHELIA_GROUP:Q} 0600
EGDIR=			${PREFIX}/share/examples/authelia
INSTALLATION_DIRS+=	bin ${EGDIR}
RCD_SCRIPTS=		authelia

# generate embeddable frontend assets w/ broccoli
pre-build:
	cd ${WRKDIR}/broccoli-* && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v .
	cd ${WRKSRC}/internal/server && ${WRKDIR}/.gopath/bin/broccoli -src ../../public_html -o public_html

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/authelia ${DESTDIR}${PREFIX}/bin/authelia
	${INSTALL_DATA} ${WRKSRC}/config.template.yml ${DESTDIR}${EGDIR}/authelia.yml

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
