# $NetBSD: Makefile,v 1.8 2024/09/03 09:22:19 fox Exp $

DISTNAME=	pfetch-1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Un1q32/}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/Un1q32/pfetch
COMMENT=	Pretty system information tool written in POSIX sh
LICENSE=	mit

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
