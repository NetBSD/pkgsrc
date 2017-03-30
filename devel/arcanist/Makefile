# $NetBSD: Makefile,v 1.7 2017/03/30 20:14:16 roy Exp $

DISTNAME=		arcanist-20170225
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=phacility/}
GITHUB_PROJECT=		arcanist
GITHUB_TAG=		822bc53ca306e06314560d8a76f68771d732e8e0

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://github.com/phacility/arcanist/
COMMENT=		Command line interface for Phabricator
LICENSE=		apache-2.0

EXTRACT_USING=		bsdtar
USE_TOOLS+=		bash bsdtar pax

DEPENDS+=		${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=		libphutil-[0-9]*:../../devel/libphutil

CONFLICTS+=		arc-[0-9]*:../../archivers/arc

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
	cd ${WRKSRC} && \
		${PAX} -rw * -s',.*\.orig$$,,' \
		${DESTDIR}${PREFIX}/${ARCANISTDIR}
	ln -s ${PREFIX}/${ARCANISTDIR}/scripts/arcanist.php \
		${DESTDIR}${PREFIX}/bin/arc

.include "../../lang/python/application.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
