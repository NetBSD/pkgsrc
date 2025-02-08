# $NetBSD: Makefile,v 1.11 2025/02/08 03:36:56 taca Exp $

DISTNAME=		libphutil-20170609
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=phacility/}
# Track the stable branch
GITHUB_PROJECT=		libphutil
GITHUB_TAG=		612619d0040b5e13c4e068dce443217abbc10a00

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://github.com/phacility/libphutil/
COMMENT=		Collection of utility classes and functions for PHP
LICENSE=		apache-2.0

EXTRACT_USING=		bsdtar
USE_TOOLS+=		bsdtar pax

REPLACE_PHP=	scripts/build_xhpast.php
REPLACE_PHP+=	scripts/daemon/exec/exec_daemon.php
REPLACE_PHP+=	scripts/daemon/launch_daemon.php
REPLACE_PHP+=	scripts/daemon/torture/resist-death.php
REPLACE_PHP+=	scripts/example/calculator.php
REPLACE_PHP+=	scripts/example/subworkflow.php
REPLACE_PHP+=	scripts/format_log.php
REPLACE_PHP+=	scripts/phutil_rebuild_map.php
REPLACE_PHP+=	scripts/phutil_symbols.php
REPLACE_PHP+=	scripts/sandpit/harden_directory.php
REPLACE_PHP+=	scripts/test/deferred_log.php
REPLACE_PHP+=	scripts/test/highlight.php
REPLACE_PHP+=	scripts/test/http.php
REPLACE_PHP+=	scripts/test/interactive_editor.php
REPLACE_PHP+=	scripts/test/lipsum.php
REPLACE_PHP+=	scripts/test/mime.php
REPLACE_PHP+=	scripts/test/paypal.php
REPLACE_PHP+=	scripts/test/progress_bar.php
REPLACE_PHP+=	scripts/test/prompt.php
REPLACE_PHP+=	scripts/test/service_profiler.php
REPLACE_PHP+=	scripts/timezones/generate_windows_timezone_map.php
REPLACE_PHP+=	scripts/update_compat_info.php
REPLACE_PHP+=	scripts/utils/directory_fixture.php
REPLACE_PHP+=	scripts/utils/lock.php
REPLACE_PHP+=	scripts/utils/prosediff.php
REPLACE_PHP+=	scripts/utils/utf8.php
REPLACE_PHP+=	src/parser/PhutilLanguageGuesser.php
REPLACE_PHP+=	src/parser/__tests__/languageguesser/php.shell-env
REPLACE_PHP+=	support/parser/generate-type-parser.php
REPLACE_PHP+=	support/xhpast/generate_nodes.php
REPLACE_PHP+=	bin/aws-s3
REPLACE_PHP+=	scripts/utils/aws-s3.php

NO_BUILD=		yes

LIBPHUTILDIR=		share/libphutil

INSTALLATION_DIRS+=	${LIBPHUTILDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${PREFIX}/${LIBPHUTILDIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
