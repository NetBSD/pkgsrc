# $NetBSD: Makefile,v 1.2 2021/03/06 18:44:05 js Exp $

DISTNAME=	element-v${PKGVERSION_NOREV}
PKGNAME=	element-web-1.7.22
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=vector-im/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
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
