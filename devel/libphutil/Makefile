# $NetBSD: Makefile,v 1.10 2024/02/19 15:43:34 taca Exp $

DISTNAME=		libphutil-20170609
PKGREVISION=		3
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

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	scripts/build_xhpast.php
SUBST_FILES.php+=	scripts/daemon/exec/exec_daemon.php
SUBST_FILES.php+=	scripts/daemon/launch_daemon.php
SUBST_FILES.php+=	scripts/daemon/torture/resist-death.php
SUBST_FILES.php+=	scripts/example/calculator.php
SUBST_FILES.php+=	scripts/example/subworkflow.php
SUBST_FILES.php+=	scripts/format_log.php
SUBST_FILES.php+=	scripts/phutil_rebuild_map.php
SUBST_FILES.php+=	scripts/phutil_symbols.php
SUBST_FILES.php+=	scripts/sandpit/harden_directory.php
SUBST_FILES.php+=	scripts/test/deferred_log.php
SUBST_FILES.php+=	scripts/test/highlight.php
SUBST_FILES.php+=	scripts/test/http.php
SUBST_FILES.php+=	scripts/test/interactive_editor.php
SUBST_FILES.php+=	scripts/test/lipsum.php
SUBST_FILES.php+=	scripts/test/mime.php
SUBST_FILES.php+=	scripts/test/paypal.php
SUBST_FILES.php+=	scripts/test/progress_bar.php
SUBST_FILES.php+=	scripts/test/prompt.php
SUBST_FILES.php+=	scripts/test/service_profiler.php
SUBST_FILES.php+=	scripts/timezones/generate_windows_timezone_map.php
SUBST_FILES.php+=	scripts/update_compat_info.php
SUBST_FILES.php+=	scripts/utils/directory_fixture.php
SUBST_FILES.php+=	scripts/utils/lock.php
SUBST_FILES.php+=	scripts/utils/prosediff.php
SUBST_FILES.php+=	scripts/utils/utf8.php
SUBST_FILES.php+=	src/parser/PhutilLanguageGuesser.php
SUBST_FILES.php+=	src/parser/__tests__/languageguesser/php.shell-env
SUBST_FILES.php+=	support/parser/generate-type-parser.php
SUBST_FILES.php+=	support/xhpast/generate_nodes.php
SUBST_FILES.php+=	bin/aws-s3
SUBST_FILES.php+=	scripts/utils/aws-s3.php
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

NO_BUILD=		yes

LIBPHUTILDIR=		share/libphutil

INSTALLATION_DIRS+=	${LIBPHUTILDIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${DESTDIR}${PREFIX}/${LIBPHUTILDIR}

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
