# $NetBSD: Makefile,v 1.3 2023/11/25 19:15:33 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.0.20141125
PKGREVISION=		1
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

INSTALLATION_DIRS+=	bin share/doc/${PKGBASE}

post-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
