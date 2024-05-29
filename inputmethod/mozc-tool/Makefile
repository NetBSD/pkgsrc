# $NetBSD: Makefile,v 1.89 2024/05/29 16:33:11 adam Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}
PKGREVISION=	2

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/bazel \
			--output_user_root=${WRKDIR}/bazel \
			--client_debug \
			build \
			gui/tool:mozc_tool \
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
