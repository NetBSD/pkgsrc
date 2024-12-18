# $NetBSD: Makefile,v 1.93 2024/12/18 01:27:03 maya Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}
PKGREVISION=	6

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/bazel \
			--output_user_root=${WRKDIR}/bazel \
			--client_debug \
			build \
			gui/tool:mozc_tool \
			--distdir=${WRKSRC}/dist \
			--jobs=${MAKE_JOBS:U1} \
			--subcommands \
			--host_action_env=PATH=${PATH} \
			--action_env=PATH=${PATH} \
			--sandbox_debug \
			--verbose_failures \
			--config oss_linux --compilation_mode opt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bazel-out/${OSDEST}//bin/gui/tool/mozc_tool \
		${DESTDIR}${PREFIX}/libexec

.include "../../inputmethod/mozc-server/Makefile.common"
.include "../../mk/bsd.pkg.mk"
