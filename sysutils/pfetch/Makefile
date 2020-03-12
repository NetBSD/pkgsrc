# $NetBSD: Makefile,v 1.3 2020/03/12 12:03:39 fox Exp $

DISTNAME=	pfetch-0.6.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/pfetch
COMMENT=	Pretty system information tool written in POSIX sh
LICENSE=	mit

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
