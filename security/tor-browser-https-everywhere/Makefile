# $NetBSD: Makefile,v 1.9 2022/03/30 09:23:29 wiz Exp $
#
# Changelog:
# https://www.eff.org/files/Changelog.txt

VERSION=	2022.3.24
DISTNAME=	https-everywhere-${VERSION}-eff
PKGNAME=	tor-browser-${DISTNAME:S/-eff//}
CATEGORIES=	security www
MASTER_SITES=	https://www.eff.org/files/
EXTRACT_SUFX=	.xpi

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.eff.org/https-everywhere
COMMENT=	HTTPS Everywhere plugin for tor-browser
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	lib/tor-browser/distribution/extensions

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/lib/tor-browser/distribution/extensions/https-everywhere-eff@eff.org.xpi

.include "../../mk/bsd.pkg.mk"
