# $NetBSD: Makefile,v 1.17 2022/06/30 11:18:11 nia Exp $

DISTNAME=		arcanist-20170609
PKGREVISION=		4
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

DEPENDS+=		${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=		libphutil-[0-9]*:../../devel/libphutil

CONFLICTS+=		arc-[0-9]*

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	scripts/arcanist.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_client.php
SUBST_FILES.php+=	scripts/hgdaemon/hgdaemon_server.php
SUBST_FILES.php+=	src/lint/linter/xhpast/rules/__tests__/inline-html/inline-html.lint-test
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

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
