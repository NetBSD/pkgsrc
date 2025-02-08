# $NetBSD: Makefile,v 1.21 2025/02/08 03:36:56 taca Exp $

DISTNAME=		arcanist-20170609
PKGREVISION=		8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=phacility/}
# Track the stable branch
GITHUB_PROJECT=		arcanist
GITHUB_TAG=		0c53a35d30e924f902510eb2e497ae5934209304

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://github.com/phacility/arcanist/
COMMENT=		Command line interface for Phabricator
LICENSE=		apache-2.0

EXTRACT_USING=		bsdtar
USE_TOOLS+=		bsdtar pax

DEPENDS+=		${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=		libphutil-[0-9]*:../../devel/libphutil

CONFLICTS+=		arc-[0-9]*

REPLACE_PHP=	scripts/arcanist.php
REPLACE_PHP+=	scripts/hgdaemon/hgdaemon_client.php
REPLACE_PHP+=	scripts/hgdaemon/hgdaemon_server.php
REPLACE_PHP+=	src/lint/linter/xhpast/rules/__tests__/inline-html/inline-html.lint-test

REPLACE_PYTHON+=	scripts/breakout.py

NO_BUILD=		yes

ARCANISTDIR=		share/arcanist

INSTALLATION_DIRS+=	${ARCANISTDIR} bin

do-install:
	cd ${WRKSRC} \
	&& ${PAX} -rw -s',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/${ARCANISTDIR}
	ln -s ${PREFIX}/${ARCANISTDIR}/scripts/arcanist.php \
		${DESTDIR}${PREFIX}/bin/arc

.include "../../lang/python/application.mk"
.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
