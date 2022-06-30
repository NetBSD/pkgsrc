# $NetBSD: Makefile,v 1.5 2022/06/30 11:18:06 nia Exp $

DISTNAME=	miniircd-2.0
PKGREVISION=	3
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=jrosdahl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/jrosdahl/miniircd/
COMMENT=	Simple Internet Relay Chat (IRC) server written in Python
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

BUILD_DEFS+=	MINIIRCD_USER MINIIRCD_GROUP
FILES_SUBST+=	PYTHONBIN=${PYTHONBIN}
FILES_SUBST+=	MINIIRCD_USER=${MINIIRCD_USER} MINIIRCD_GROUP=${MINIIRCD_GROUP}

.include "../../mk/bsd.prefs.mk"

MINIIRCD_USER?=		miniircd
MINIIRCD_GROUP?=	nobody

PKG_GROUPS=	${MINIIRCD_GROUP}
PKG_USERS=	${MINIIRCD_USER}:${MINIIRCD_GROUP}

RCD_SCRIPTS=	miniircd

REPLACE_PYTHON+=	miniircd
REPLACE_PYTHON+=	test.py

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 2.0

INSTALLATION_DIRS=	sbin share/doc/miniircd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/miniircd ${DESTDIR}${PREFIX}/sbin/miniircd
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/miniircd/README

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
