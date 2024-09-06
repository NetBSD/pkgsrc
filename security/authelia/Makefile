# $NetBSD: Makefile,v 1.50 2024/09/06 18:48:54 bsiegert Exp $

DISTNAME=	authelia-4.38.9
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=authelia/}
GITHUB_TAG=	v4.38.9		# can't use PKGVERSION_NOREV

FE_DISTNAME=			authelia-${GITHUB_TAG}-public_html.tar.gz
AUTHELIA_DISTFILES+=		${FE_DISTNAME}
SITES.${FE_DISTNAME}=		\
	${MASTER_SITE_GITHUB:=authelia/}authelia/releases/download/${GITHUB_TAG}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKSRC}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.authelia.com/
COMMENT=	Single Sign-On Multi-Factor portal for web apps
LICENSE=	apache-2.0

DISTFILES=		${DEFAULT_DISTFILES} ${AUTHELIA_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES} ${AUTHELIA_DISTFILES}

CHECK_PORTABILITY_SKIP+=	entrypoint.sh
CHECK_PORTABILITY_SKIP+=	internal/suites/example/compose/redis/entrypoint.sh

.include "go-modules.mk"

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

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/authelia ${DESTDIR}${PREFIX}/bin/authelia
	${INSTALL_DATA} ${WRKSRC}/config.template.yml ${DESTDIR}${EGDIR}/authelia.yml

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
