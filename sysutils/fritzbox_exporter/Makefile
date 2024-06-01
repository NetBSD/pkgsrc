# $NetBSD: Makefile,v 1.5 2024/06/01 14:03:02 bsiegert Exp $

DISTNAME=	fritzbox_exporter-1.1.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ndecker/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ndecker/fritzbox_exporter
COMMENT=	Fritz!Box Upnp statistics exporter for Prometheus
LICENSE=	apache-2.0

LOGDIR=				${VARBASE}/log/fritzbox_exporter
FRITZBOX_EXPORTER_USER?=	fbexport
FRITZBOX_EXPORTER_GROUP?=	fbexport
OWN_DIRS_PERMS+=		${LOGDIR} ${FRITZBOX_EXPORTER_USER} ${FRITZBOX_EXPORTER_GROUP} 0700
PKG_USERS_VARS+=		FRITZBOX_EXPORTER_USER
PKG_GROUPS_VARS+=		FRITZBOX_EXPORTER_GROUP
PKG_GROUPS=			${FRITZBOX_EXPORTER_GROUP}
PKG_USERS=			${FRITZBOX_EXPORTER_USER}:${FRITZBOX_EXPORTER_GROUP}
RCD_SCRIPTS=			fritzbox_exporter

FILES_SUBST+=		FRITZBOX_EXPORTER_USER=${FRITZBOX_EXPORTER_USER:Q}
FILES_SUBST+=		FRITZBOX_EXPORTER_GROUP=${FRITZBOX_EXPORTER_GROUP:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	share/doc/fritzbox_exporter

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/fritzbox_exporter

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
