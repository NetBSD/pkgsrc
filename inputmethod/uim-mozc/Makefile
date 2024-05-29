# $NetBSD: Makefile,v 1.75 2024/05/29 16:33:12 adam Exp $

PKGNAME=	${DISTNAME:S/mozc-/uim-mozc-/}
PKGREVISION=	2

TOOL_DEPENDS+=	bazel-[0-9]*:../../devel/bazel

INSTALLATION_DIRS+=	lib/uim/plugin share/uim/pixmaps

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PREFIX}/bin/bazel \
			--output_user_root=${WRKDIR}/bazel \
			--client_debug \
			build \
			unix/uim:uim-mozc \
			--host_action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--action_env=CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR} \
			--host_action_env=PATH=${PATH} \
			--action_env=PATH=${PATH} \
			--sandbox_debug \
			--verbose_failures \
			--subcommands \
			--config oss_linux --compilation_mode opt \
			--experimental_cc_shared_library

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bazel-out/${OSDEST}/bin/unix/uim/libuim-mozc.so \
		${DESTDIR}${PREFIX}/lib/uim/plugin/libuim-mozc.so
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-tool.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_selector.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-properties.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_config_dialog.png
	${INSTALL_DATA} ${WRKSRC}/data/images/unix/ui-dictionary.png \
		${DESTDIR}${PREFIX}/share/uim/pixmaps/mozc_tool_dictionary_tool.png
	${INSTALL_DATA} ${WRKSRC}/uim/Mozc/scm/mozc-custom.scm \
		${DESTDIR}${PREFIX}/share/uim
	${INSTALL_DATA} ${WRKSRC}/uim/Mozc/scm/mozc-key-custom.scm \
		${DESTDIR}${PREFIX}/share/uim
	${INSTALL_DATA} ${WRKSRC}/uim/Mozc/scm/mozc.scm \
		${DESTDIR}${PREFIX}/share/uim

UIM_MODULES=	mozc
.include "../../inputmethod/uim/modules.mk"

.include "../../inputmethod/uim/buildlink3.mk"
.include "../../inputmethod/uim-mozc/Makefile.common"
.include "../../mk/bsd.pkg.mk"
