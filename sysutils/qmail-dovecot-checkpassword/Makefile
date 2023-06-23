# $NetBSD: Makefile,v 1.2 2023/06/23 19:36:39 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.0.20141125
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=Securepoint/}
GITHUB_PROJECT=		qmail-dovecot-checkpassword
GITHUB_TAG=		9ff0341fa93d638c0249d0ae90fe20349ce9ab37

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/Securepoint/qmail-dovecot-checkpassword/
COMMENT=		DJB-style checkpassword for Dovecot auth socket
#LICENSE=		# TODO: (see mk/license.mk)

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	checkpasswd.c
SUBST_VARS.paths=	VARBASE

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
