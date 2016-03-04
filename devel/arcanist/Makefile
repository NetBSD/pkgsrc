# $NetBSD: Makefile,v 1.2 2016/03/04 15:23:29 youri Exp $

DISTNAME=		arcanist-20160224
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=phacility/}
GITHUB_PROJECT=		arcanist
GITHUB_TAG=		086f5399bfbb65513b1b0e2c5371522202a9beb7

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://github.com/phacility/arcanist/
COMMENT=		Command line interface for Phabricator
LICENSE=		apache-2.0

USE_TOOLS+=		bash pax

DEPENDS=		${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS=		${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS=		libphutil-[0-9]*:../../devel/libphutil

REPLACE_BASH+=		bin/arc

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	scripts/arcanist.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_client.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_server.php
SUBST_FILES.php+=	src/lint/linter/xhpast/rules/__tests__/inline-html/inline-html.lint-test
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_PYTHON+=	scripts/breakout.py

NO_BUILD=	yes

ARCANISTDIR=	share/arcanist

INSTALLATION_DIRS+=	${ARCANISTDIR} bin

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${PREFIX}/${ARCANISTDIR}

post-install:
	ln -s ${PREFIX}/${ARCANISTDIR}/bin/arc ${PREFIX}/bin/arc

DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl

.include "../../lang/python/application.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
