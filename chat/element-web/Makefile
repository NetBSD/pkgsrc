# $NetBSD: Makefile,v 1.42 2026/03/25 23:14:25 gdt Exp $

DISTNAME=	element-v${PKGVERSION_NOREV}
PKGNAME=	element-web-1.12.12
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=element-hq/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

# GPG key:
#   https://packages.riot.im/element-release-key.asc
#   712B FBEE 92DC A452 52DB  17D7 C7BE 97EF A179 B100
#   
# GPG signature:
#   https://github.com/vector-im/element-web/releases/download/v${PKGVERSION_NOREV}/element-v${PKGVERSION_NOREV}.tar.gz.asc

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://element.io/
COMMENT=	Matrix web client
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/element-v${PKGVERSION_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/element-web

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/element-web

.include "../../mk/bsd.pkg.mk"
