# $NetBSD: Makefile,v 1.2 2020/10/24 22:44:29 wiz Exp $

DISTNAME=	collectd-cgp-1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	sysutils
GITHUB_PROJECT=	CGP
MASTER_SITES=	${MASTER_SITE_GITHUB:=pommi/}
GITHUB_TAG=	v${DISTNAME:S/collectd-cgp-//}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/pommi/
COMMENT=	Graphical web-based front-end for visualizing RRD collected
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax unzip
EXTRACT_ONLY=	# empty

INSTALLATION_DIRS=	share/collectd-graph-panel

WRKSRC=		${WRKDIR}/CGP-1

DEPENDS+=	${PHP_PKG_PREFIX}-rrd>=1.1.3:../../databases/php-rrd

PHP_VERSIONS_ACCEPTED=	56 # php-rrd

do-install:
	cd ${DESTDIR}/${PREFIX}/${INSTALLATION_DIRS} && \
	unzip -ojqL ${DISTDIR}/${DISTFILES}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
